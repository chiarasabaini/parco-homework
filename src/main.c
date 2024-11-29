#include "test.h"
#include "utils.h"
#include "matrix_operations.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    global_log = init_log();
    
    for(int i=0; i < 5; i++){
        test_performance();
    }

    close_log(global_log);

    return 0;
}
