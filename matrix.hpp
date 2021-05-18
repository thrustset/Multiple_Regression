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

    auto friend operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream &;

    auto operator=(Matrix const &source) -> Matrix &;
    auto operator+(Matrix const &source) const -> Matrix;

    [[nodiscard]] auto getValue(int i, int j) const -> double;
};