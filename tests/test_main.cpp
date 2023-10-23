#include <gtest/gtest.h>
#include "../src/MatrixHandler.h"

// Testing size of transition matrix
TEST(MatrixHandlerTest, TransitionMatrixSize) {
    MatrixHandler matrix_handler;
    vector<vector<double>> transition_matrix = matrix_handler.get_transition_matrix(1, 1, 1, 1);
    
    // Expecting the transition matrix size to be 10x10
    EXPECT_EQ(transition_matrix.size(), 10);
    for (const auto& row : transition_matrix) {
        EXPECT_EQ(row.size(), 10);
    }
}

// Testing that matrix^0 is the identity matrix
TEST(MatrixHandlerTest, MatrixPowerIdentity) {
    MatrixHandler matrix_handler;
    int n = 0;
    vector<vector<double>> matrix = { {1, 0}, {0, 1} };

    vector<vector<double>> result = matrix_handler.matrix_power(matrix, n, 2);
    
    // Expecting the result to be the identity matrix
    EXPECT_EQ(result, matrix);
}

// Testing that matrix power function is correct
TEST(MatrixHandlerTest, MatrixPower) {
    MatrixHandler matrix_handler;
    int n = 2;
    vector<vector<double>> matrix = { {1, 2}, {3, 4} };

    vector<vector<double>> result = matrix_handler.matrix_power(matrix, n, 2);

    // The result should be the matrix multiplied by itself
    vector<vector<double>> expected = { {7, 10}, {15, 22} };
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
