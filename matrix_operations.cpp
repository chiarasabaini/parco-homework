#include "matrix_operations.hpp"
#include <ctime>
#include <cstdlib>


/**
 * @brief Initialize a matrix with random float values
 *
 * @param M matrix to initialize
 * @param n size of the matrix M[n][n]
 */
void init_mat(float** M, int n) {
    srand(time(NULL)); // seed the random number generator
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}


/**
 * @brief Check if a matrix is symmetric
 *
 * @param M matrix to check.
 * @param n size of the matrix M[n][n]
 * @return true if the matrix is symmetric, false otherwise
 */
bool checkSym(float** M, int n) {
    clock_t start = clock();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (M[i][j] != M[j][i]) {
                return false;
            }
        }
    }

    clock_t end = clock();
    double time_sym = double(end - start) / CLOCKS_PER_SEC;
    printf("\n CPU time sequential (clock) = %12.4g s\n", (time_sym)/1000000.0);

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
    clock_t start = clock();

    if (checkSym(M, n)) { // if M is symmetric, T = M
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                T[i][j] = M[i][j];
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                T[j][i] = M[i][j];
            }
        }
    }

    clock_t end = clock();
    double time_trans = double(end - start) / CLOCKS_PER_SEC;
    printf("\n CPU time sequential (clock) = %12.4g sec\n", (time_trans)/1000000.0);
}

void main(){}