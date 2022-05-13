#ifndef KP7_MATRIX_H
#define KP7_MATRIX_H

typedef struct Matrix {
    int CIP[100];
    int PI[100];
    int YE[100];
} Matrix;

void  inputMatrix(Matrix *matrix1,Matrix *matrix2,int *m1,int *n1,int *m2,int *n2);
void printMatrix(Matrix *matrix,int m,int n);
void chechDiag(Matrix *matrix);
Matrix *matrixMultipy(Matrix *matrix1,Matrix *matrix2,m1,n1,m2,n2);
#endif //KP7_MATRIX_H