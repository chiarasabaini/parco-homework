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
    for(int size = MIN_MAT_SIZE; size <= MAX_MAT_SIZE; size *= 2){
        // allocate memory for matrices
        float** M = new_mat(size);
        float** T = new_mat(size);
    
        // test symmetry check
        for (int i = 0; i < 5; i++) {
            init_symmetric_mat(M, size);

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

            // TASK 3: parallelized transposition using OpenMP
            checkSymOMP(M, size);
            matTransposeOMP(M, T, size);
            check_transpose(M, T, size);
        }

        for (int i = 0; i < 5; i++) {
            init_mat(M, size);
            
            // TASK 1: sequential matrix transposition
            matTranspose(M, T, size);
            check_transpose(M, T, size);
            // print_matrix(T, size);

            // TASK 2: implicitly parellelized transposition
            matTransposeImp(M, T, size);
            check_transpose(M, T, size);
            // print_matrix(T, size);

            // TASK 3: parallelized transposition using OpenMP
            matTransposeOMP(M, T, size);
            check_transpose(M, T, size);
        }
            


        free_mat(M, size);
        free_mat(T, size);
    }
}
