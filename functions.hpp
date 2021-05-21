#pragma once
#include <cmath>
#include "sym_matrix.hpp"
#include "matrix.hpp"

auto transform(SymMatrix const &symMatrix)  -> Matrix;
auto transform(Matrix const &matrix)        -> SymMatrix;
auto transpose(Matrix const &matrix)        -> Matrix;
auto cholesky(SymMatrix const &symMatrix)   -> Matrix;
auto unityMatrix(int size)                  -> SymMatrix;
