#include "utils.h"
#include "matrix_operations.h"

#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// TASK 1

bool checkSym(float** M, int n) {
    double start = omp_get_wtime();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (M[i][j] != M[j][i]) {
                return false;
            }
        }
    }

    double end = omp_get_wtime();
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));
    print_log(global_log, "Sequential Symmetry Check", SYMMETRY, SEQUENTIAL, n, n_threads, end - start);

    return true;
}


void matTranspose(float** M, float** T, int n) {
    double start = omp_get_wtime();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[j][i] = M[i][j];
        }
    }

    double end = omp_get_wtime();
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));
    print_log(global_log, "Sequental Transposition", TRANSPOSITION, SEQUENTIAL, n, n_threads, end - start);
}


// TASK 2

bool checkSymImp(float** M, int n) {
    double start = omp_get_wtime();

    for (int i = 0; i < n - 1; i++) {

        #pragma unroll(4)
        for (int j = i + 1; j < n; j++) {
            if (M[i][j] != M[j][i]) {
                return false;
            }
        }
    }

    double end = omp_get_wtime();
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));
    print_log(global_log, "Implicit Symmetry Check", SYMMETRY, IMPLICIT, n, n_threads, end - start);

    return true;
}


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
    print_log(global_log, "Implicit Transposition", TRANSPOSITION, IMPLICIT, n, n_threads, end - start);
}

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
    print_log(global_log, "Implicit Transposition BlockBased", BLOCKS, n, n_threads, end - start);
}
*/

// TASK 3

bool checkSymOMP(float** M, int n) {
    double start = omp_get_wtime();

    int i;
    bool is_sym = true;

    #pragma omp parallel for collapse(1) reduction(&:is_sym)
    for (i = 0; i < n - 1; i++) {

        #pragma omp parallel for collapse(1) reduction(&:is_sym)
        for (int j = i + 1; j < n; j++) {
            if (M[i][j] != M[j][i]) {
                is_sym = false;
        }
    }
    }

    double end = omp_get_wtime();
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));
    print_log(global_log, "OMP Parallelized Symmetry Check", SYMMETRY, OMP, n, n_threads, end - start);

    return is_sym;
}


void matTransposeOMP(float** M, float** T, int n){
    double start = omp_get_wtime();

    int i, j;
    
    #pragma omp parallel for collapse(2)
    for (i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            T[j][i] = M[i][j];
        }
    }


    double end = omp_get_wtime();
    int n_threads = atoi(getenv("OMP_NUM_THREADS"));
    print_log(global_log, "OMP Parallelized Transposition", TRANSPOSITION, OMP, n, n_threads, end - start);
}


bool check_transpose(float** M, float** T, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (M[i][j] != T[j][i]) {
                return false;
            }
        }
    }
    return true;
}
