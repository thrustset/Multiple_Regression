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

auto operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream & {
    os << "Matrix:\n";
    os << "\tsize = " << matrix.size << "\n";

    for(int i = 0; i < matrix.size; i++) {
        os << "\t";
        for(int j = 0; j < matrix.size; j++)
            os << matrix.getValue(i, j) << "\t";
        os << "\n";
    }

    return os;
}

auto Matrix::operator=(Matrix const &source) -> Matrix & {
    if(size != source.size) {
        std::cout << "Warning!\nThe sizes of two matrix are not equals to each other!\n";
        size = source.size;
        delete[] value;
        value = new double[size * (size + 1) / 2];
    }
    for(int i = 0; i < size * (size + 1) / 2; i++)
        value[i] = source.value[i];
}

auto Matrix::operator+(Matrix const &source) const -> Matrix {
    if(size != source.size) {
        std::cout << "Error!\nThe sizes of two matrix are not equals to each other!\n";
        return *this;
    } else {
        auto sum = Matrix(*this);
        for(int i = 0; i < size * (size + 1) / 2; i++)
            sum.value[i] += source.value[i];
        return sum;
    }
}

auto Matrix::getValue(int i, int j) const -> double {
    if(i <= j)
        return value[i * (size - 1) - i * (i - 1) / 2 + j];
    return getValue(j, i);
}