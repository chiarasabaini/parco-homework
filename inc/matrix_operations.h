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
 * @brief Transpose a given matrix
 * 
 * @param[in] M matrix
 * @param[in] n size of matrix M[n][n]
 * @param[out] T result of the transposition
 */
void matTranspose(float** M, float** T, int n);


// TASK 2
/**
 * @brief Check if a matrix is symmetric, implicitly optimized
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
// #pragma GCC target "march=native" // not available in C
#pragma GCC optimize ("O2,tree-vectorize")
bool checkSymImp(float** M, int n);


/**
 * @brief Transpose a given matrix, implicitly optimized
 * 
 * @param[in] M matrix
 * @param[in] n size of matrix M[n][n]
 * @param[out] T result of the transposition
 */
// #pragma GCC target "march=native" // not available in C
#pragma GCC optimize ("O2,tree-vectorize")
void matTransposeImp(float** M, float** T, int n);


// /**
//  * @brief matrix transposition using block transposition
//  * 
//  * @param[in] M matrix
//  * @param[out] T M transposed
//  * @param[in] n size of matrix M[n][n]
//  */
// void matTransposeBlock(float** M, float** T, int n);


// TASK 3
/**
 * @brief Check if a matrix is symmetric, parallelized using OpenMP
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
bool checkSymOMP(float** M, int n);


/**
 * @brief Transpose a given matrix, parallelized using OpenMP
 * 
 * @param[in] M matrix
 * @param[in] n size of matrix M[n][n]
 * @param[out] T result of the transposition
 */
void matTransposeOMP(float** M, float** T, int n);

// TEST

/**
 * @brief Check if transposition return the correct result
 * 
 * @param M matrix
 * @param T result of transposition
 * @param size size of given matrices
 * @return true if it's been trasposed correctly, false otherwise
 */
bool check_transpose(float **M, float **T, int size);


#endif // MATRIX_OPERATIONS_H