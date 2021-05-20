#include "matrix.hpp"

Matrix::Matrix() :
    numOfRows{0},
    numOfColumns{0},
    value{nullptr}
{}

Matrix::Matrix(int numOfRows, int numOfColumns) :
    numOfRows{numOfRows},
    numOfColumns{numOfColumns},
    value{new double*[numOfRows]}
{
    for(int i = 0; i < numOfRows; i++)
        this->value[i] = new double[numOfColumns];
}

Matrix::Matrix(int numOfRows, int numOfColumns, const double **value) :
    numOfRows{numOfRows},
    numOfColumns{numOfColumns},
    value{new double*[numOfRows]}
{
    for(int i = 0; i < numOfRows; i++) {
        this->value[i] = new double[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            this->value[i][j] = value[i][j];
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

Matrix::Matrix(SymMatrix &source) :
    numOfRows{source.getSize()},
    numOfColumns{source.getSize()},
    value{new double*[numOfRows]}
{
    for(int i = 0; i < numOfRows; i++) {
        this->value[i] = new double[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            this->value[i][j] = source.getValue(i, j);
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < numOfRows; i++)
        delete [] this->value[i];
    delete [] this->value;
}

auto operator<<(std::ostream &os, Matrix const &matrix) -> std::ostream & {
    os << "Matrix:\n";
    os << "\tnumOfRows = " << matrix.numOfRows << "\n";
    os << "\tnumOfColumns = " << matrix.numOfColumns << "\n";

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
                    sum += value[i][k] * source.value[k][i];
                product.setValue(i, j, sum);
            }
        }
        return product;
    } else {
        std::cout << "Error!\nThe matrices are not available for multiplication!\n";
        return *this;
    }
}

auto Matrix::isSymmetrical() const -> bool {
    if(numOfRows == numOfColumns)
        return true;
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

auto Matrix::getValue(int i, int j) const -> double {
    return value[i][j];
}

auto Matrix::setValue(int i, int j, double newValue) -> void {
    value[i][j] = newValue;
}

auto isAvailableMultiply(Matrix const &matrix1, Matrix const &matrix2) -> bool {
    if(matrix1.getNumOfColumns() == matrix2.getNumOfRows())
        return true;
    return false;
}