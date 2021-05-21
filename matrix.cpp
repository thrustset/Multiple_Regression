#include "matrix.hpp"

Matrix::Matrix() :
    numOfRows{0},
    numOfColumns{0},
    value{nullptr}
{}

Matrix::Matrix(int numOfRows, int numOfColumns, double **value) :
    numOfRows{numOfRows},
    numOfColumns{numOfColumns},
    value{new double*[numOfRows]}
{
    if(value != nullptr) {
        for (int i = 0; i < numOfRows; i++) {
            this->value[i] = new double[numOfColumns];
            for (int j = 0; j < numOfColumns; j++)
                this->value[i][j] = value[i][j];
        }
    } else {
        for (int i = 0; i < numOfRows; i++)
            this->value[i] = new double[numOfColumns];
    }
}

Matrix::Matrix(Matrix const &source) :
    numOfRows{source.numOfRows},
    numOfColumns{source.numOfColumns},
    value{new double*[numOfRows]}
{
    for(int i = 0; i < numOfRows; i++) {
        this->value[i] = new double[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            this->value[i][j] = source.value[i][j];
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < numOfRows; i++)
        delete [] this->value[i];
    delete [] this->value;
}

auto operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream & {
    os << "Matrix\t";
    os << "[" << matrix.numOfRows << "x" << matrix.numOfColumns << "]\n";

    for(int i = 0; i < matrix.numOfRows; i++) {
        for(int j = 0; j < matrix.numOfColumns; j++) {
            os << "\t" << matrix.value[i][j];
        }
        os << "\n";
    }

    return os;
}

auto Matrix::operator=(Matrix const &source) -> Matrix & {
    for(int i = 0; i < numOfRows; i++)
        delete [] value[i];
    delete [] value;

    numOfRows = source.numOfRows;
    numOfColumns = source.numOfColumns;
    value = new double*[numOfRows];
    for(int i = 0; i < numOfColumns; i++) {
        value[i] = new double[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            value[i][j] = source.value[i][j];
    }

    return *this;
}

auto Matrix::operator*(Matrix const &source) const -> Matrix {
    if(isAvailableMultiply(*this, source)) {
        auto product = Matrix(numOfRows, source.numOfColumns);
        double sum;
        for(int i = 0; i < product.numOfRows; i++) {
            for(int j = 0; j < product.numOfColumns; j++) {
                sum = 0;
                for(int k = 0; k < numOfColumns; k++)
                    sum += value[i][k] * source.value[k][j];
                product.setValue(i, j, sum);
            }
        }
        return product;
    }
    std::cout << "Error!\n";
    std::cout << "The matrices are not available for multiplication!\n";
    return *this;
}

auto Matrix::operator*(FVector array) const -> Matrix {
    auto product = Matrix(numOfRows, 1);
    for(int i = 0; i < numOfRows; i++) {
        auto sum = 0.0;
        for(int k = 0; k < numOfColumns; k++)
            sum += array.at(k)(value[i][k]);
        product.setValue(i, 0, sum);
    }
    return product;
}

auto Matrix::operator|(FVector array) const -> Matrix {
    auto result = Matrix(numOfRows, numOfColumns + 1);
    for(int i = 0; i < numOfRows; i++) {
        result.setValue(i, 0, 1);
        for(int j = 0; j < numOfColumns; j++) {
            result.setValue(i, j + 1, array.at(j)(value[i][j]));
        }
    }
    return result;
}

auto Matrix::isSquare() const -> bool {
    if(numOfRows == numOfColumns)
        return true;
    return false;
}

auto Matrix::isSymmetrical() const -> bool {
    if(isSquare()) {
        for(int i = 0; i < numOfRows; i++) {
            for(int j = i + 1; j < numOfColumns; j++) {
                if(value[i][j] != value[j][i])
                    return false;
            }
        }
        return true;
    }
    return false;
}

auto Matrix::getSize() const -> int {
    if(isSymmetrical())
        return numOfRows;
    std::cout << "Warning!\nThe matrix is not symmetrical!\n";
    return 0;
}

auto Matrix::getNumOfRows() const -> int {
    return numOfRows;
}

auto Matrix::getNumOfColumns() const -> int {
    return numOfColumns;
}

auto Matrix::getValue() const -> double ** {
    return value;
}

auto Matrix::getValue(int i) const -> double* {
    return value[i];
}

auto Matrix::getValue(int i, int j) const -> double {
    return value[i][j];
}

auto Matrix::setNumOfRows(int set) -> void {
    numOfRows = set;
}

auto Matrix::setNumOfColumns(int set) -> void {
    numOfColumns = set;
}

auto Matrix::setValue(int i, int j, double set) -> void {
    value[i][j] = set;
}

auto isAvailableMultiply(Matrix const &matrix1, Matrix const &matrix2) -> bool {
    if(matrix1.getNumOfColumns() == matrix2.getNumOfRows())
        return true;
    return false;
}