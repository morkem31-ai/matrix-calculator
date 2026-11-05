#include <iostream>

#include "matrix.h"

int main() {
    double arr_a[] = {1, 2, 3, 4};
    double arr_b[] = {5, 6, 7, 8};

    matrix::Matrix a = matrix::matrix_from_array(arr_a, 2, 2);
    matrix::Matrix b = matrix::matrix_from_array(arr_b, 2, 2);

    matrix::Matrix sum = matrix::matrix_add(a, b);
    matrix::Matrix product = matrix::matrix_multiply(a, b);

    std::cout << "Matrix A:\n";
    matrix::print_matrix(a);

    std::cout << "Matrix B:\n";
    matrix::print_matrix(b);

    std::cout << "Sum A + B:\n";
    matrix::print_matrix(sum);

    std::cout << "Product A * B:\n";
    matrix::print_matrix(product);

    matrix::Matrix identity = matrix::matrix_identity(3);

    std::cout << "Identity matrix 3x3:\n";
    matrix::print_matrix(identity);

    matrix::free_matrix(identity);

    matrix::free_matrix(a);
    matrix::free_matrix(b);
    matrix::free_matrix(sum);
    matrix::free_matrix(product);

    return 0;
}
