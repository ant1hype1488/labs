#ifndef KP7_MATRIX_H
#define KP7_MATRIX_H

typedef struct Matrix {
    int CIP[100];
    int PI[100];
    int YE[100];
} Matrix;

void inputMatrix(Matrix *matrix,int m,int n);
void createMatrix(Matrix* m);
void printMatrix(Matrix *matrix,int m,int n);

#endif //KP7_MATRIX_H