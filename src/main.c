#include "utils.h"
#include "matrix_operations.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the matrix size: ");
    scanf("%d", &n);

    // allocate memory for matrices
    float** M = malloc(sizeof(float) * n);
    float** T = malloc(sizeof(float) * n);
    for (int i = 0; i < n; ++i) {
        M[i] = malloc(sizeof(float) * n);
        T[i] = malloc(sizeof(float) * n);
    }

    for(int i=0; i < 5; i++){
        test_performance(M, T);
    }

    // free memory
    for (int i = 0; i < n; ++i) {
        free(M[i]);
        free(T[i]);
    }
    free(M);
    free(T);

    return 0;
}