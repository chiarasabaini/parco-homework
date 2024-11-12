/**
 * @file mat_ops.hpp
 * @brief Header file for matrix operations
 */

#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

#include <iostream>

using namespace std;


/**
 * @brief Initialize a matrix with random values
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 */
void init_mat(float** M, int n);


/**
 * @brief Check if a matrix is symmetric
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
bool checkSym(float** M, int n);

/**
 * @brief matrix transposition
 * 
 * @param[in] M matrix
 * @param[out] T M transposed
 * @param[in] n size of matrix M[n][n]
 */
void matTranspose(float** M, float** T, int n);

#endif // MATRIX_OPERATIONS_HPP