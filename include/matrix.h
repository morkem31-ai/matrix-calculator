#pragma once

/**
 * @file matrix.h
 * @brief Библиотека для работы с матрицами.
 */

namespace matrix {

/**
 * @brief Структура для хранения матрицы.
 *
 * Содержит двумерный динамический массив
 * и количество строк и столбцов.
 *
 * @warning Выделенная память освобождается через free_matrix().
 */
struct Matrix {
    double** data;  ///< Двумерный массив элементов.
    int rows;       ///< Количество строк.
    int cols;       ///< Количество столбцов.
};

/**
 * @brief Создаёт матрицу заданного размера.
 *
 * Все элементы матрицы инициализируются нулями.
 *
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Матрица с выделенной памятью.
 * @exception std::invalid_argument Если размер не положительный.
 * @exception std::bad_alloc Если не удалось выделить память.
 * @note Сложность O(rows * cols).
 */
Matrix create_matrix(int rows, int cols);

/**
 * @brief Освобождает память матрицы.
 *
 * @param m Матрица для освобождения.
 * @warning Исходный указатель не обнуляется,
 * поскольку матрица передаётся по значению.
 */
void free_matrix(Matrix m);

/**
 * @brief Складывает две матрицы.
 * @param a Первая матрица.
 * @param b Вторая матрица.
 * @return Новая матрица с результатом сложения.
 * @exception std::invalid_argument Если матрицы некорректны
 * или их размеры не совпадают.
 * @warning Результат необходимо освободить через free_matrix().
 */
Matrix matrix_add(Matrix a, Matrix b);

/**
 * @brief Умножает две матрицы.
 * @param a Первая матрица размера M x N.
 * @param b Вторая матрица размера N x K.
 * @return Новая матрица размера M x K.
 * @exception std::invalid_argument Если матрицы некорректны
 * или количество столбцов a не равно количеству строк b.
 * @note Сложность O(M * N * K).
 * @warning Результат необходимо освободить через free_matrix().
 */
Matrix matrix_multiply(Matrix a, Matrix b);

/**
 * @brief Выводит матрицу в консоль.
 * @param m Матрица для вывода.
 * @note Числа выводятся с двумя знаками после запятой.
 * Большие матрицы отображаются в сокращённом виде.
 */
void print_matrix(Matrix m);

/**
 * @brief Создаёт матрицу из одномерного массива.
 * @param data Указатель на исходный массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Новая матрица с элементами исходного массива.
 * @exception std::invalid_argument Если указатель равен nullptr
 * или размеры некорректны.
 * @warning Результат необходимо освободить через free_matrix().
 */
Matrix matrix_from_array(double* data, int rows, int cols);

/**
 * @brief Создаёт единичную матрицу заданного размера.
 *
 * На главной диагонали находятся единицы,
 * остальные элементы равны нулю.
 *
 * @param size Размер квадратной матрицы.
 * @return Единичная матрица размера size x size.
 * @exception std::invalid_argument Если size <= 0.
 * @note Сложность O(size * size).
 * @warning Результат необходимо освободить через free_matrix().
 */
Matrix matrix_identity(int size);

}  // namespace matrix
