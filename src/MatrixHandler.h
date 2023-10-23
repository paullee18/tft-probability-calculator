#ifndef MATRIXHANDLER_H
#define MATRIXHANDLER_H

#include "MatrixHandlerInterface.h"

class MatrixHandler : public MatrixHandlerInterface {
public:
    vector<vector<double>> get_transition_matrix(int, int, int, int);
    vector<vector<double>> matrix_power(vector<vector<double>>, int, int);    

    private:
    vector<vector<double>> matrix_multiply(const vector<vector<double>>&, const vector<vector<double>>&, int);
};

#endif