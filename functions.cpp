#include "functions.hpp"

auto transform(SymMatrix const &symMatrix) -> Matrix {
    int size = symMatrix.getSize();
    auto matrix = Matrix(size, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++)
            matrix.setValue(i, j, symMatrix.getValue(i, j));
    }
    return matrix;
}

auto transform(Matrix const &matrix) -> SymMatrix {
    if(matrix.isSymmetrical()) {
        int size = matrix.getNumOfRows();
        auto symMatrix = SymMatrix(size);

        for(int i = 0; i < size; i++) {
            for(int j = i; j < size; j++)
                symMatrix.setValue(i, j, matrix.getValue(i, j));
        }

        return symMatrix;
    } else {
        std::cout << "Error!\n";
        std::cout << "The matrix is not symmetrical!\n";
        return SymMatrix();
    }
}

auto transpose(Matrix const &matrix) -> Matrix {
    int numOfRows = matrix.getNumOfColumns();
    int numOfColumns = matrix.getNumOfRows();

    auto newMatrix = Matrix(numOfRows, numOfColumns);
    for(int i = 0; i < numOfRows; i++) {
        for(int j = 0; j < numOfColumns; j++)
            newMatrix.setValue(i, j, matrix.getValue(j, i));
    }

    return newMatrix;
}

auto cholesky(SymMatrix const &symMatrix) -> Matrix {
    int size = symMatrix.getSize();
    double sum;

    auto matrix = Matrix(size, size);
    for(int j = 0; j < size; j++) {
        for(int i = 0; i < j; i++)
            matrix.setValue(i, j, 0);

        sum = 0;
        for(int k = 0; k < j; k++)
            sum += pow(matrix.getValue(j, k), 2);
        matrix.setValue(j, j, sqrt(symMatrix.getValue(j, j) - sum));

        for(int i = j + 1; i < size; i++) {
            sum = 0;
            for(int k = 0; k < j - 1; k++)
                sum += matrix.getValue(i, k) * matrix.getValue(j, k);
            matrix.setValue(i, j, (symMatrix.getValue(i, j) - sum) / matrix.getValue(j, j));
        }
    }

    return matrix;
}

auto unityMatrix(int size) -> SymMatrix {
    auto unity = SymMatrix(size);
    for(int i = 0; i < size; i++) {
        unity.setValue(i, i, 1);
        for(int j = i + 1; j < size; j++)
            unity.setValue(i, j, 0);
    }
    return unity;
}