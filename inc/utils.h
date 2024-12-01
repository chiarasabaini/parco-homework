/**
 * @file utils.h
 * @brief Header file for useful functions
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdio.h>

#define MIN_MAT_SIZE 16
#define MAX_MAT_SIZE 4096

/**
 * @brief Functions that can be tested
 */
typedef enum {
    TRANSPOSITION = 0,
    SYMMETRY = 1,
    N_FUNCTIONS
} func_t;

/**
 * @brief Convert func_t to string
 * 
 * @param function function type
 * @return const char* 
 */
const char* func2str(func_t function);

/**
 * @brief Implementations that can be tested
 */


typedef enum {
  SEQUENTIAL = 0,
  IMPLICIT = 1,
  OMP = 2,
  // BLOCKS = 4,
  N_IMPLEMENTATIONS
} imp_t;

/**
 * @brief Convert imp_t to string
 * 
 * @param implementation implementation type
 * @return const char* 
 */
const char* imp2str(imp_t implementation);

// MATRIX

/**
 * @brief Initialize a matrix with random values
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 */
float** new_mat(int n);


/**
 * @brief Free previously allocated matrix memory
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 */
void free_mat(float **M, int n);


/**
 * @brief Initialize given matrix, populating it with random values
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 */
void init_mat(float** M, int n);


/**
 * @brief Initialize given matrix, populating it with random values to make it symmetric
 * 
 * @param M matrix
 * @param n size of matrix M[n][n]
 */
void init_symmetric_mat(float** M, int n);


// LOG

extern FILE* global_log;

/**
 * @brief Open and initialize log file
 * 
 * @return FILE*
 */
FILE* init_log();


/**
 * @brief Close previously opened log file
 * 
 * @param log file pointer
 */
void close_log(FILE *log);


/**
 * @brief Print log string on file and, if in debugging mode, on screen
 * 
 * @param msg debug message
 * @param func executing function 
 * @param imp implementation type
 * @param size matrix size
 * @param n_threads number of threads used to run
 * @param execution_time time elapsed between start and end of execution of the function
 */
void print_log(FILE *log, const char *msg, func_t func, imp_t imp, int size, int n_threads, double execution_time);

#endif // UTILS_H