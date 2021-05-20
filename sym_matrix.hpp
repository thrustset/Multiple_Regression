#pragma once
#include <iostream>
#include "matrix.hpp"

class SymMatrix {
private:
    int size;
    double *value;
public:
    SymMatrix();
    explicit SymMatrix(int size);
    SymMatrix(int size, double const *value);
    SymMatrix(SymMatrix const &matrix);
    SymMatrix(Matrix const &matrix);
    ~SymMatrix();

    auto friend operator<<(std::ostream &os, SymMatrix const &matrix) -> std::ostream &;

    auto operator=(SymMatrix const &source) -> SymMatrix &;
    auto operator+(SymMatrix const &source) const -> SymMatrix;
    auto operator*(SymMatrix const &source) const -> SymMatrix;

    [[nodiscard]] auto getSize() const -> int;
    [[nodiscard]] auto getValue(int i, int j) const -> double;
    auto setValue(int i, int j, double set) -> void;

    auto determinant() -> double;
};