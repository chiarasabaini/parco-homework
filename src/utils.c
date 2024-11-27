#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


const char* func2str(func_t function) {
    switch (function) {
        case TRANSPOSITION:
            return "TRANSPOSITION";
        case SYMMETRY:
            return "SYMMETRY";
        default:
            return "UNKNOWN";
    }
}

const char* imp2str(imp_t implementation) {
    switch (implementation) {
        case SEQUENTIAL:
            return "SEQUENTIAL";
        case IMPLICIT:
            return "IMPLICIT";
        case OMP:
            return "OMP";
        default:
            return "UNKNOWN";
    }
}

void print_log(const char *msg, func_t func, imp_t imp, float size, int n_threads, double execution_time) {
    printf("%s:\n\tmatrix size: %f\n\tn_threads: %d\n\texecution time:%f\n", msg, size, n_threads, execution_time);

    FILE *fp = fopen("..\\out\\data.csv", "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    if (file_size == 0) {
        fprintf(fp, "Matrix Size, Threads, Function, Implementation, Execution Time\n");
    }

    fprintf(fp, "%f, %d, %s, %s, %f\n", size, n_threads, func2str(func), imp2str(imp), execution_time);

    fclose(fp);
}

void print_matrix(float** M, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%f ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

float **new_mat(int size) {
    float **M =  malloc(sizeof(float) * size);
    for (int i = 0; i < size; ++i) {
            M[i] = malloc(sizeof(float) * size);
    }
    return M;
}

void init_random_mat(float** M, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j] = ((float)rand()) / RAND_MAX;
        }
    }
}

void free_mat(float **M, int n) {
    for (int i = 0; i < n; ++i) {
        free(M[i]);
    }
    free(M);
}


bool check_transpose(float **M, float **T, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (M[i][j] != T[j][i]) {
                return false;
            }
        }
    }
    return true;
}
