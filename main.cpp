#include <iostream>
#include <cmath>
#include "sym_matrix.hpp"
#include "matrix.hpp"
#include "functions.hpp"

auto main() -> int {
    int size = 3;

    auto *value = new double[size * (size + 1) / 2];
    value[0] = 6.25;
    value[1] = -1.0;
    value[2] = 0.50;
    value[3] = 5.00;
    value[4] = 2.12;
    value[5] = 3.60;

    auto symMatrix1 = SymMatrix(size, value);
    std::cout << symMatrix1;
    std::cout << cholesky(symMatrix1);

    return 0;
}