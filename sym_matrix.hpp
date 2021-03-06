#pragma once
#include <iostream>

class SymMatrix {
private:
    int size;
    double *value;
public:
    SymMatrix();
    explicit SymMatrix(int size);
    SymMatrix(int size, double const *value);
    SymMatrix(SymMatrix const &matrix);
    ~SymMatrix();

    auto friend operator<<(std::ostream &os, SymMatrix const &matrix) -> std::ostream &;

    auto operator=(SymMatrix const &source) -> SymMatrix &;
    auto operator+(SymMatrix const &source) const -> SymMatrix;
    auto operator*(SymMatrix const &source) const -> SymMatrix;

    auto getSize() const -> int;
    auto getValue(int i, int j) const -> double;
    auto setValue(int i, int j, double set) -> void;
};