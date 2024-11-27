/**
 * @file matrix_operations.h
 * @brief Header file for matrix operations
 */

#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <stdbool.h>


// TASK 1
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


// TASK 2
/**
 * @brief Check if a matrix is symmetric
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
bool checkSymImp(float** M, int n);

/**
 * @brief matrix transposition
 * 
 * @param[in] M matrix
 * @param[out] T M transposed
 * @param[in] n size of matrix M[n][n]
 */
void matTransposeImp(float** M, float** T, int n);

/**
 * @brief matrix transposition using block transposition
 * 
 * @param[in] M matrix
 * @param[out] T M transposed
 * @param[in] n size of matrix M[n][n]
 */
void matTransposeBlock(float** M, float** T, int n);


// TASK 3
/**
 * @brief Check if a matrix is symmetric
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
bool checkSymOMP(float** M, int n);

/**
 * @brief matrix transposition, parallelized using OpenMP
 * 
 * @param[in] M matrix
 * @param[out] T M transposed
 * @param[in] n size of matrix M[n][n]
 */
void matTransposeOMP(float** M, float** T, int n);

#endif // MATRIX_OPERATIONS_H