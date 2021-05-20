#pragma once
#include <iostream>

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

    [[nodiscard]] auto isSquare() const -> bool;
    [[nodiscard]] auto isSymmetrical() const -> bool;

    [[nodiscard]] auto getSize() const -> int;
    [[nodiscard]] auto getNumOfRows() const -> int;
    [[nodiscard]] auto getNumOfColumns() const -> int;

    [[nodiscard]] auto getValue() const -> double **;
    [[nodiscard]] auto getValue(int i) const -> double *;
    [[nodiscard]] auto getValue(int i, int j) const -> double;

    auto setNumOfRows(int set) -> void;
    auto setNumOfColumns(int set) -> void;
    auto setValue(int i, int j, double set) -> void;
};

auto isAvailableMultiply(Matrix const &matrix1, Matrix const &matrix2) -> bool;