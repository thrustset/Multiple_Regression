#pragma once
#include <iostream>

class Matrix {
private:
    int size;
    double *value;
public:
    Matrix();
    Matrix(int size, double const *value);
    Matrix(Matrix const &matrix);
    ~Matrix();

    /*
    auto friend operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream &;
     */
};