#include <iostream>
#include "sym_matrix.hpp"
#include "matrix.hpp"

auto main() -> int {
    int size = 5;

    auto *value = new double[size * (size + 1) / 2];
    for(int i = 0; i < size * (size + 1) / 2; i++)
        value[i] = i;

    auto a = SymMatrix(size, value);
    delete [] value;
    auto b = a * a;

    std::cout << a;
    std::cout << b;

    Matrix a1 = Matrix(a);

    return 0;
}
