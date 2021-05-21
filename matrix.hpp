#pragma once
#include <iostream>
#include <functional>

using FVector = std::vector<std::function<double(double)>>;

class Matrix {
private:
    int numOfRows;
    int numOfColumns;
    double **value;
public:
    Matrix();
    Matrix(int numOfRows, int numOfColumns, double **value = nullptr);
    Matrix(Matrix const &source);
    ~Matrix();

    auto friend operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream &;

    auto operator=(Matrix const &source) -> Matrix &;
    auto operator*(Matrix const &source) const -> Matrix;

    auto operator*(FVector array) const -> Matrix;
    auto operator|(FVector array) const -> Matrix;

    auto isSquare() const -> bool;
    auto isSymmetrical() const -> bool;

    auto getSize() const -> int;
    auto getNumOfRows() const -> int;
    auto getNumOfColumns() const -> int;

    auto getValue() const -> double **;
    auto getValue(int i) const -> double *;
    auto getValue(int i, int j) const -> double;

    auto setNumOfRows(int set) -> void;
    auto setNumOfColumns(int set) -> void;
    auto setValue(int i, int j, double set) -> void;
};

auto isAvailableMultiply(Matrix const &matrix1, Matrix const &matrix2) -> bool;