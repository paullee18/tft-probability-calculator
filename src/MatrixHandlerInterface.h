#ifndef MATRIXHANDLERINTERFACE_H
#define MATRIXHANDLERINTERFACE_H

#include <vector>

using namespace std;
class MatrixHandlerInterface {
    public:
    virtual vector<vector<double>> get_transition_matrix(int, int, int, int) = 0;
    virtual vector<vector<double>> matrix_power(vector<vector<double>>, int, int) = 0;    

    private:
    virtual vector<vector<double>> matrix_multiply(const vector<vector<double>>& matrix_1, const vector<vector<double>>& matrix_2, int length) = 0;
};

#endif