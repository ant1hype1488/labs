#include <stdio.h>

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#include "matrix.h"
int main() {
    Matrix * matrix = malloc(sizeof(Matrix));;

    int n,m;
    n = 4;
    m = 4;
    inputMatrix(matrix,n,m);
    for (int i = 0; i < 4; ++i) {
        printf("%d ",matrix->CIP[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d ",matrix->PI[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; ++i) {
        printf("%d ",matrix->YE[i]);
    }
    printf("\n");
    printf("\n");


    printMatrix(matrix,m,n);

    return 0;
}






