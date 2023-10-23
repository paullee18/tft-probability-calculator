#include "MatrixHandler.h"
#include "ProbabilityCalculator.h"
#include <pthread.h>
#include <vector>

using namespace std;

vector<vector<double>> MatrixHandler::get_transition_matrix(int level, int tier, int copies_out, int same_tier_out) {
    vector<vector<double>> matrix(10, vector<double>(10, 0));
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (i==9 && j==9) {
                matrix[i][j] = 1;
                break;
            }
            ProbabilityCalculator probability_calculator;
            double p = probability_calculator.get_probability(level, tier, copies_out+i, same_tier_out+i);
            if (j==i) {
                matrix[i][j] = 1-p;
            } else if (j==i+1) {
                matrix[i][j] = p;
            }
        }
    }
    return matrix;
}

// Get the result of a square matrix raised to power n
vector<vector<double>> MatrixHandler::matrix_power(vector<vector<double>> matrix, int n, int length) {    
    vector<vector<double>> result(length, vector<double>(length, 0));
    if (n == 0) {
        // Return identity matrix as probability from going to i copies to i copies is always 1
        for (int i=0; i<length; i++) {
            result[i][i] = 1;
        }
        return result;
    }

    if (n==1) {
        return matrix;
    }
    
    vector<vector<double>> halved = matrix_power(matrix, n/2, length);
    if (n % 2) {
        result = matrix_multiply(matrix, matrix_multiply(halved, halved, length), length);
    } else {
        result = matrix_multiply(halved, halved, length);
    }
    return result;
}

// For passing arguments into worker function
struct ThreadArgs {
    int length;
    int row;
    vector<vector<double>>* result;
    const vector<vector<double>>* matrix_1;
    const vector<vector<double>>* matrix_2;
};

void* matrix_multiply_thread(void* args) {
    ThreadArgs* t_args = (ThreadArgs*) args;

    for (int j=0; j<t_args->length; j++) {
        for (int k=0; k<t_args->length; k++) {
            (*t_args->result)[t_args->row][j] += (*t_args->matrix_1)[t_args->row][k] * (*t_args->matrix_2)[k][j];
        }
    }

    return nullptr;
}

// Get the result of the multiplication of two square matrices of equal sizes
vector<vector<double>> MatrixHandler::matrix_multiply(const vector<vector<double>>& matrix_1, const vector<vector<double>>& matrix_2, int length) {
    vector<vector<double>> result(length, vector<double>(length, 0));
    pthread_t threads[length];
    ThreadArgs thread_args[length];

    for (int i=0; i<length;i++) {
        thread_args[i] = {length, i, &result, &matrix_1, &matrix_2};
        pthread_create(&threads[i], nullptr, matrix_multiply_thread, &thread_args[i]);
    }

    for (int i = 0; i < length; i++) {
        pthread_join(threads[i], nullptr);
    }

    return result;
}
