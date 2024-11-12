// task 1: sequential implementation

#include "matrix_operations.hpp"
#include <iostream>

using namespace std;

int main() {
    int n;
    printf("Enter the matrix size: ");
    scanf("%d", &n);

    // allocate memory for matrices
    float** M = new float*[n];
    float** T = new float*[n];
    for (int i = 0; i < n; ++i) {
        M[i] = new float[n];
        T[i] = new float[n];
    }


    // TASK 1
    // initialize matrix M[n][n] with random float values
    init_mat(M, n);
    // sequential matrix transposition
    matTranspose(M, T, n);

    // free memory
    for (int i = 0; i < n; ++i) {
        delete[] M[i];
        delete[] T[i];
    }
    delete[] M;
    delete[] T;

    return 0;
}