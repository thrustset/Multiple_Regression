#include <iostream>
#include "matrix.hpp"

auto main() -> int {
    int size = 4;

    auto *value = new double[size * (size + 1) / 2];
    for(int i = 0; i < size * (size + 1) / 2; i++)
        value[i] = i;

    auto a = Matrix(size, value);
    std::cout << a;

    return 0;
}
