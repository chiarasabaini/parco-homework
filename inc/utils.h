/**
 * @file utils.h
 * @brief Header file for useful functions
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef enum {
    TRANSPOSITION = 0,
    SYMMETRY = 1,
    N_FUNCTIONS
} func_t;
const char* func2str(func_t function);

typedef enum {
  SEQUENTIAL = 0,
  IMPLICIT = 2,
  OMP = 4,
  // BLOCKS = 4,
  N_IMPLEMENTATIONS
} imp_t;
const char* imp2str(imp_t implementation);

/**
 * @brief Initialize a matrix with random values
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 */
void init_mat(float** M, int n);


/**
 * @brief 
 * 
 * @param msg 
 * @param func 
 * @param imp 
 * @param size 
 * @param n_threads 
 * @param execution_time 
 */
void print_log(const char *msg, func_t func, imp_t imp, float size, int n_threads, double execution_time);



/**
 * @brief 
 * 
 * @param M 
 * @param T 
 * @param size 
 * @return true if it's been trasposed correctly, false otherwise
 */
bool check_transpose(float **M, float **T, int size);

/**
 * @brief
 * 
 * @param M matrix
 * @param T matrix
 */
void test_performance(float** M, float** T);


#endif // UTILS_H