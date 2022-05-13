#include <stdio.h>

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#include "matrix.h"
int main() {
    Matrix * matrix1 = malloc(sizeof(Matrix));
    Matrix * matrix2 = malloc(sizeof(Matrix));

    Matrix * mult = malloc(sizeof(Matrix));


    int n1,m1;
    int n2,m2;
    inputMatrix(matrix1,matrix2,&m1,&n1,&m2,&n2);

    printf("Матрица 1 \n");

    printMatrix(matrix1,m1,n1);
    printf("\n");
    printf("Матрица 2 \n");


    printMatrix(matrix2,m2,n2);
    printf("\n");
    printf("Умножение матриц \n");

    mult = matrixMultipy(matrix1,matrix2,m1,n1,m2,n2);
    printMatrix(mult,m1,n2);
    printf("\n");

    printf("Проверка диагональности матрицы 1 :\n");
    chechDiag(matrix1);
    printf("\n");
    printf("\n");

    printf("Проверка диагональности умножения  :\n");
    chechDiag(mult);
    printf("\n");


    return 0;
}






