#include <gtest/gtest.h>

#include <stdexcept>

#include "matrix.h"

TEST(MatrixTest, CreateMatrix) {
    matrix::Matrix a = matrix::create_matrix(3, 4);

    EXPECT_EQ(a.rows, 3);
    EXPECT_EQ(a.cols, 4);
    EXPECT_NE(a.data, nullptr);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            EXPECT_DOUBLE_EQ(a.data[i][j], 0.0);
        }
    }

    matrix::free_matrix(a);
}

TEST(MatrixTest, Addition) {
    double x[] = {1, 2, 3, 4};
    double y[] = {5, 6, 7, 8};

    matrix::Matrix a = matrix::matrix_from_array(x, 2, 2);
    matrix::Matrix b = matrix::matrix_from_array(y, 2, 2);
    matrix::Matrix c = matrix::matrix_add(a, b);

    EXPECT_DOUBLE_EQ(c.data[0][0], 6.0);
    EXPECT_DOUBLE_EQ(c.data[0][1], 8.0);
    EXPECT_DOUBLE_EQ(c.data[1][0], 10.0);
    EXPECT_DOUBLE_EQ(c.data[1][1], 12.0);

    matrix::free_matrix(a);
    matrix::free_matrix(b);
    matrix::free_matrix(c);
}

TEST(MatrixTest, Multiplication) {
    double x[] = {1, 2, 3, 4};
    double y[] = {5, 6, 7, 8};

    matrix::Matrix a = matrix::matrix_from_array(x, 2, 2);
    matrix::Matrix b = matrix::matrix_from_array(y, 2, 2);
    matrix::Matrix c = matrix::matrix_multiply(a, b);

    EXPECT_DOUBLE_EQ(c.data[0][0], 19.0);
    EXPECT_DOUBLE_EQ(c.data[0][1], 22.0);
    EXPECT_DOUBLE_EQ(c.data[1][0], 43.0);
    EXPECT_DOUBLE_EQ(c.data[1][1], 50.0);

    matrix::free_matrix(a);
    matrix::free_matrix(b);
    matrix::free_matrix(c);
}
TEST(MatrixTest, Identity3x3) {
    matrix::Matrix a = matrix::matrix_identity(3);

    EXPECT_EQ(a.rows, 3);
    EXPECT_EQ(a.cols, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                EXPECT_DOUBLE_EQ(a.data[i][j], 1.0);
            } else {
                EXPECT_DOUBLE_EQ(a.data[i][j], 0.0);
            }
        }
    }

    matrix::free_matrix(a);
}

TEST(MatrixTest, Identity1x1) {
    matrix::Matrix a = matrix::matrix_identity(1);

    EXPECT_EQ(a.rows, 1);
    EXPECT_EQ(a.cols, 1);
    EXPECT_DOUBLE_EQ(a.data[0][0], 1.0);

    matrix::free_matrix(a);
}

TEST(MatrixTest, IdentityInvalidSize) {
    EXPECT_THROW(matrix::matrix_identity(0), std::invalid_argument);
    EXPECT_THROW(matrix::matrix_identity(-3), std::invalid_argument);
}

TEST(MatrixTest, CreateMatrixInvalidSize) {
    EXPECT_THROW(matrix::create_matrix(0, 3), std::invalid_argument);
    EXPECT_THROW(matrix::create_matrix(3, -1), std::invalid_argument);
}
TEST(MatrixTest, AdditionSizeMismatch) {
    matrix::Matrix a = matrix::create_matrix(2, 2);
    matrix::Matrix b = matrix::create_matrix(3, 3);

    EXPECT_THROW(matrix::matrix_add(a, b), std::invalid_argument);

    matrix::free_matrix(a);
    matrix::free_matrix(b);
}

TEST(MatrixTest, MultiplicationSizeMismatch) {
    matrix::Matrix a = matrix::create_matrix(2, 3);
    matrix::Matrix b = matrix::create_matrix(2, 2);

    EXPECT_THROW(matrix::matrix_multiply(a, b), std::invalid_argument);

    matrix::free_matrix(a);
    matrix::free_matrix(b);
}
