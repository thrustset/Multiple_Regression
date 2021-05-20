#include "sym_matrix.hpp"

SymMatrix::SymMatrix() :
    size{0},
    value{nullptr}
{}

SymMatrix::SymMatrix(int size) :
    size{size},
    value{new double[size * (size + 1) / 2]}
{}

SymMatrix::SymMatrix(int size, double const *value) :
    size{size},
    value{new double[size * (size + 1) / 2]}
{
    for(int i = 0; i < size * (size + 1) / 2; i++)
        this->value[i] = value[i];
}

SymMatrix::SymMatrix(SymMatrix const &matrix) :
    size{matrix.size},
    value{new double[size * (size + 1) / 2]}
{
    for(int i = 0; i < size * (size + 1) / 2; i++)
        this->value[i] = matrix.value[i];
}

SymMatrix::~SymMatrix() {
    delete [] value;
}

auto operator<<(std::ostream &os, SymMatrix const &matrix) -> std::ostream & {
    os << "SymMatrix:\n";
    os << "\tsize = " << matrix.size << "\n";

    for(int i = 0; i < matrix.size; i++) {
        os << "\t";
        for(int j = 0; j < matrix.size; j++)
            os << matrix.getValue(i, j) << "\t";
        os << "\n";
    }

    return os;
}

auto SymMatrix::operator=(SymMatrix const &source) -> SymMatrix & {
    if(size != source.size) {
        std::cout << "Warning!\nThe sizes of two matrix are not equals to each other!\n";
        size = source.size;
        delete[] value;
        value = new double[size * (size + 1) / 2];
    }
    for(int i = 0; i < size * (size + 1) / 2; i++)
        value[i] = source.value[i];
    return *this;
}

auto SymMatrix::operator+(SymMatrix const &source) const -> SymMatrix {
    if(size != source.size) {
        std::cout << "Error!\nThe sizes of two matrix are not equals to each other!\n";
        return *this;
    } else {
        auto sum = SymMatrix(*this);
        for(int i = 0; i < size * (size + 1) / 2; i++)
            sum.value[i] += source.value[i];
        return sum;
    }
}

auto SymMatrix::operator*(SymMatrix const &source) const -> SymMatrix {
    if(size != source.size) {
        std::cout << "Error!\nThe sizes of two matrix are not equals to each other!\n";
        return *this;
    } else {
        auto product = SymMatrix(size);
        double sum;

        for(int i = 0; i < size; i++) {
            for(int j = i; j < size; j++) {
                sum = 0;
                for(int k = 0; k < size; k++) {
                    sum += getValue(i, k) * source.getValue(k, j);
                }
                product.setValue(i, j, sum);
            }
        }

        return product;
    }
}

auto SymMatrix::getSize() const -> int {
    return size;
}

auto SymMatrix::getValue(int i, int j) const -> double {
    if(i < 0 || i >= size || j < 0 || j >= size)
        return 0;
    if(i >= j)
        return value[i + j * (size - 1) - j * (j - 1) / 2];
    return getValue(j, i);
}

auto SymMatrix::setValue(int i, int j, double set) -> void {
    if(i >= j) {
        value[i + j * (size - 1) - j * (j - 1) / 2] = set;
    } else {
        setValue(j, i, set);
    }
}