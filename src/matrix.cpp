
#include "matrix.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

namespace matrix {

Matrix create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }

    Matrix m{nullptr, rows, cols};
    m.data = new double*[rows]{};

    try {
        for (int i = 0; i < rows; i++) {
            m.data[i] = new double[cols]{};
        }
    } catch (...) {
        for (int i = 0; i < rows; i++) {
            delete[] m.data[i];
        }
        delete[] m.data;
        throw;
    }

    return m;
}

void free_matrix(Matrix m) {
    if (m.data == nullptr) {
        return;
    }

    for (int i = 0; i < m.rows; i++) {
        delete[] m.data[i];
    }

    delete[] m.data;
}
Matrix matrix_add(Matrix a, Matrix b) {
    if (a.data == nullptr || b.data == nullptr ||
        a.rows <= 0 || a.cols <= 0 ||
        b.rows <= 0 || b.cols <= 0) {
        throw std::invalid_argument("Invalid matrix");
    }

    if (a.rows != b.rows || a.cols != b.cols) {
        throw std::invalid_argument("Matrix dimensions must match");
    }

    Matrix result = create_matrix(a.rows, a.cols);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }

    return result;
}
Matrix matrix_multiply(Matrix a, Matrix b) {
    if (a.data == nullptr || b.data == nullptr ||
        a.rows <= 0 || a.cols <= 0 ||
        b.rows <= 0 || b.cols <= 0) {
        throw std::invalid_argument("Invalid matrix");
    }

    if (a.cols != b.rows) {
        throw std::invalid_argument("Incompatible matrix dimensions");
    }

    Matrix result = create_matrix(a.rows, b.cols);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return result;
}

void print_matrix(Matrix m) {
    if (m.data == nullptr || m.rows <= 0 || m.cols <= 0) {
        std::cout << "[Empty matrix]\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);

    const int max_rows = 10;
    const int max_cols = 8;

    for (int i = 0; i < m.rows; i++) {
        if (m.rows > max_rows && i == 5) {
            std::cout << "[ ... ]\n";
            i = m.rows - 5;
        }

        std::cout << "[";

        for (int j = 0; j < m.cols; j++) {
            if (m.cols > max_cols && j == 4) {
                std::cout << "  ...";
                j = m.cols - 4;
            }

            std::cout << " " << std::setw(6) << m.data[i][j];
        }

        std::cout << " ]\n";
    }

    if (m.rows > max_rows || m.cols > max_cols) {
        std::cout << "Matrix " << m.rows << "x" << m.cols
                  << " (shortened output)\n";
    }
}

Matrix matrix_from_array(double* data, int rows, int cols) {
    if (data == nullptr || rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Invalid array or matrix dimensions");
    }

    Matrix result = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i * cols + j];
        }
    }

    return result;
}
Matrix matrix_identity(int size) {
    if (size <= 0) {
        throw std::invalid_argument("Matrix size must be positive");
    }

    Matrix result = create_matrix(size, size);

    for (int i = 0; i < size; i++) {
        result.data[i][i] = 1.0;
    }

    return result;
}
}
