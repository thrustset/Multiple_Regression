#pragma once
#include <iostream>
#include "sym_matrix.hpp"

class Matrix {
private:
    int numOfRows;
    int numOfColumns;
    double **value;
public:
    Matrix();
    Matrix(int numOfRows, int numOfColumns);
    Matrix(int numOfRows, int numOfColumns, double const **value);
    Matrix(Matrix const &source);
    explicit Matrix(SymMatrix &source);
    ~Matrix();

    auto friend operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream &;

    auto operator=(Matrix const &source) -> Matrix &;
    auto operator*(Matrix const &source) const -> Matrix;

    [[nodiscard]] auto isSymmetrical() const -> bool;
    [[nodiscard]] auto getSize() const -> int;
    [[nodiscard]] auto getNumOfRows() const -> int;
    [[nodiscard]] auto getNumOfColumns() const -> int;

    [[nodiscard]] auto getValue(int i, int j) const -> double;
    auto setValue(int i, int j, double newValue) -> void;
};

auto isAvailableMultiply(Matrix const &matrix1, Matrix const &matrix2) -> bool;