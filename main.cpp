#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <cmath>

#include "sym_matrix.hpp"
#include "matrix.hpp"
#include "functions.hpp"

auto main() -> int {
    std::ifstream file;
    file.open("../input.txt");
    if(!file) {
        std::cout << "Check file's path!\n";
        std::cout << "The program is finished!\n";
        return 0;
    }

    int numOfMeasure;
    int dim;
    file >> dim >> numOfMeasure;

    if(dim != 3) {
        std::cout << "dimension != 3\n";
        std::cout << "The program is finished!\n";
        return 0;
    }

    auto X = Matrix(numOfMeasure, dim);
    auto Y = Matrix(numOfMeasure, 1);
    for(int i = 0; i < numOfMeasure; i++) {
        double value;
        for(int j = 0; j < dim; j++) {
            file >> value;
            X.setValue(i, j, value);
        }
        file >> value;
        Y.setValue(i, 0, value);
    }

    auto funcArray = FVector();
    funcArray.emplace_back(exp);
    funcArray.emplace_back(sin);
    funcArray.emplace_back(cos);

    auto F = X | funcArray;
    std::cout << std::setprecision(2) << F;

    auto D = transpose(F) * F;
    std::cout << std::setprecision(4) << D;

    auto D_new = transform(D);
    std::cout << std::setprecision(4) << cholesky(D_new);

    return 0;
}