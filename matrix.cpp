#include "matrix.hpp"

Matrix::Matrix() :
    size{0},
    value{nullptr}
{}

Matrix::Matrix(int size, double const *value) :
    size{size},
    value{new double[size * (size + 1) / 2]}
{
    for(int i = 0; i < size * (size + 1) / 2; i++)
        this->value[i] = value[i];
}

Matrix::Matrix(Matrix const &matrix) :
    size{matrix.size},
    value{new double[size * (size + 1) / 2]}
{
    for(int i = 0; i < size * (size + 1) / 2; i++)
        this->value[i] = matrix.value[i];
}

Matrix::~Matrix() {
    delete [] value;
}

/*
auto operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream & {
    os << "Matrix:\n";
    os << "size = " << matrix.size << "\n";
    for(int i = 0; i < )
}
 */