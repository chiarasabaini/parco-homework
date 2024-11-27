#include "utils.h"
#include "matrix_operations.h"
#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>


// TASK 1

/**
 * @brief Check if a matrix is symmetric
 *
 * @param M matrix to check.
 * @param n size of the matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
bool checkSym(float** M, int n) {
    double start = omp_get_wtime();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (M[i][j] != M[j][i]) {
                return false;
            }
        }
    }

    double end = omp_get_wtime();

    int n_threads = atoi(getenv("OMP_NUM_THREADS"));

    print_log("Sequental Symmetry Check", SYMMETRY, SEQUENTIAL, n, n_threads, end - start);

    return true;
}


/**
 * @brief Transpose a matrix
 *
 * @param[in] M original matrix
 * @param[out] T transposed matrix
 * @param[in] n size of the matrices M[n][n] and T[n][n]
 */
void matTranspose(float** M, float** T, int n) {
    double start = omp_get_wtime();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            T[j][i] = M[i][j];
        }
    }

    double end = omp_get_wtime();
    
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));

    print_log("Sequental Transposition", TRANSPOSITION, SEQUENTIAL, n, n_threads, end - start);
}


// TASK 2

/**
 * @brief Check if a matrix is symmetric
 *
 * @param M matrix to check.
 * @param n size of the matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
bool checkSymImp(float** M, int n) {
    double start = omp_get_wtime();

    for (int i = 0; i < n - 1; ++i) {

        #pragma unroll(4)
        for (int j = i + 1; j < n; ++j) {
            if (M[i][j] != M[j][i]) {
                return false;
            }
        }
    }

    double end = omp_get_wtime();
    
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));

    print_log("Implicit Symmetry Check", SYMMETRY, IMPLICIT, n, n_threads, end - start);

    return true;
}

/**
 * @brief matrix transposition using block segmentation
 * 
 * @param[in] M original matrix
 * @param[out] T transposed matrix
 * @param[in] n size of the matrices M[n][n] and T[n][n]
 */

void matTransposeImp(float** M, float** T, int n){
    double start = omp_get_wtime();

    for (int i = 0; i < n; ++i) {
        #pragma unroll (4)
        for (int j = 0; j < n; ++j) {
            T[j][i] = M[i][j];
        }
    }

    double end = omp_get_wtime();
    
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));

    print_log("Implicit Transposition", TRANSPOSITION, IMPLICIT, n, n_threads, end - start);
}

/**
 * @brief matrix transposition using block segmentation
 * 
 * @param[in] M original matrix
 * @param[out] T transposed matrix
 * @param[in] n size of the matrices M[n][n] and T[n][n]
 */
/*
void matTransposeBlock(float** M, float** T, int n){
    int bi,bj,i,j;
    int nBlocks = 32; // nBlocks < n, otherwise it won't work
    int blockSize = n / nBlocks;

    printf("%d\n", blockSize);

    double start = omp_get_wtime();
    
    for(bi = 0; bi < n; bi += blockSize){
        for(bj = 0; bj < n; bj += blockSize){
            for(i = bi; i < bi + blockSize; i++){
                for(j = bj; j < bj + blockSize; j++){
                    T[j][i]=M[i][j];
                }
            }
        }
    }
    
    double end = omp_get_wtime();
    
    
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));
    print_log("Implicit Transposition BlockBased", BLOCKS, n, n_threads, end - start);
}
*/

// TASK 3

/**
 * @brief Check if a matrix is symmetric
 *
 * @param M matrix to check.
 * @param n size of the matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
bool checkSymOMP(float** M, int n) {
    double start = omp_get_wtime();

    int i;
    bool is_sym = true;

    #pragma omp parallel for collapse(1) shared(M, n, i) reduction(&:is_sym)
    for (i = 0; i < n - 1; ++i) {
        
        #pragma omp parallel for collapse(1) reduction(&:is_sym)
        for (int j = i + 1; j < n; ++j) {
            if (M[i][j] != M[j][i]) {
                is_sym = false;
        }
    }
    }

    double end = omp_get_wtime();
    
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));
    print_log("OMP Parallelized Symmetry Check", SYMMETRY, OMP, n, n_threads, end - start);

    return is_sym;
}

/**
 * @brief matrix transposition, parallelized using OpenMP
 * 
 * @param[in] M matrix
 * @param[out] T M transposed
 * @param[in] n size of matrix M[n][n]
 */
void matTransposeOMP(float** M, float** T, int n){
    double start = omp_get_wtime();

    int i, j;
    
    #pragma omp parallel for collapse(2)
    for (i=0; i < n; ++i) {
        for (j=0; j < n; ++j) {
            T[j][i] = M[i][j];
        }
    }


    double end = omp_get_wtime();
    
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));
    print_log("OMP Parallelized Transposition", TRANSPOSITION, OMP, n, n_threads, end - start);
}