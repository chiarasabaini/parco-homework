#include "test.h"
#include "utils.h"
#include "matrix_operations.h"

/**
 * @brief
 * 
 * @param M matrix
 * @param T matrix
 */    
void test_performance(){
    char* filename = "data.csv";

    for(int size = MIN_MAT_SIZE; size < MAX_MAT_SIZE; size *= 2){
        // allocate memory for matrices
        float** M = new_mat(size);
        float** T = new_mat(size);
        init_random_mat(M, size);
        
        if (checkSym(M, size)) {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    T[i][j] = M[i][j];
                }
            }
        } else {
            // TASK 1: sequential matrix transposition
            checkSym(M, size);
            matTranspose(M, T, size);
            check_transpose(M, T, size);
            // print_matrix(T, size);

            // TASK 2: implicitly parellelized transposition
            
            checkSymImp(M, size);
            matTransposeImp(M, T, size);
            
            check_transpose(M, T, size);
            // print_matrix(T, size);

            checkSymOMP(M, size);
            matTransposeOMP(M, T, size);
            check_transpose(M, T, size);

        }
        free_mat(M, size);
        free_mat(T, size);
    }
}
