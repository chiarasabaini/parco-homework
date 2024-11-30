#include "utils.h"

#include <time.h>
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


// LOG

FILE* global_log;

FILE* init_log() {
    time_t current_time;
    time(&current_time);
    
    struct tm* time_info;
    time_info = localtime(&current_time);

    char time_string[32];
    strftime(time_string, 32, "%Y%m%d_%H%M%S", time_info);

    int n_threads = atoi(getenv("OMP_NUM_THREADS"));

    char filepath[255];
    snprintf(filepath, 255, "../out/data/%s_%d_log.csv", time_string, n_threads);

    FILE* log = fopen(filepath, "w");
    if (log == NULL) {
        perror("Error opening file");
    } else {
        fprintf(log, "Matrix Size,Threads,Function,Implementation,Execution Time\n");
    }

    return log;
}


 void print_log(FILE* log, const char* msg, func_t func, imp_t imp, int size, int n_threads, double execution_time) {

    #if LOG_DEBUG == 1
        printf("%s:\n\tmatrix size: %d\n\tn_threads: %d\n\texecution time:%f\n", msg, size, n_threads, execution_time);
    #endif

    fprintf(log, "%d,%d,%s,%s,%f\n", size, n_threads, func2str(func), imp2str(imp), execution_time);
}


void close_log(FILE* log) {
    if(log) {
        fclose(log);
    }
}


void print_matrix(float** M, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%f ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// MATRIX
float** new_mat(int size) {
    float** M = malloc(sizeof(float*) * size);

    for (int i = 0; i < size; i++) {
            M[i] = malloc(sizeof(float) * size);
    }
    return M;
}


void init_mat(float** M, int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = ((float)rand()) / RAND_MAX;
        }
    }
}


void free_mat(float **M, int n) {
    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    
    free(M);
}

