#include "stdlib.h"
#include "stdio.h"

#include "matrix.h"


void  inputMatrix(Matrix *matrix1,Matrix *matrix2,int *m1,int *n1,int *m2,int *n2){
    FILE *fptr;
    int num ;
    int count =0;
    if ((fptr = fopen("data.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    fscanf(fptr, "%d %d", m1,n1);

    for (int i = 0; i <*m1 ; ++i) {
        if((count  == matrix1->CIP[i-1]) ){
            *(matrix1->CIP + i) = 0;
        } else{
            *(matrix1->CIP + i) = count;

        }
        for (int j = 0; j < *n1; ++j) {
            fscanf(fptr, "%d", &num);
            if(num !=0){
                *(matrix1->PI + count) = j;
                *(matrix1->YE + count) = num;
                count++;
            }

        }

    }

    fscanf(fptr, "%d %d", m2,n2);
    count = 0;
    for (int i = 0; i <*m2 ; ++i) {
        if((count  == matrix2->CIP[i-1]) ){
            *(matrix2->CIP + i) = 0;
        } else{
            *(matrix2->CIP + i) = count;

        }
        for (int j = 0; j < *n2; ++j) {
            fscanf(fptr, "%d", &num);
            if(num !=0){
                *(matrix2->PI + count) = j;
                *(matrix2->YE + count) = num;
                count++;
            }

        }

    }
    fclose(fptr);
}
void printMatrix(Matrix *matrix,int m,int n){
    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n ; ++j) {
            if (i !=m -1 ){
                if (matrix->CIP[i+1]!=count&& matrix->CIP[i+1]!=0 ){

                    if (matrix->PI[count] == j){
                        printf("%d ",matrix->YE[count]);
                        count ++;
                    }else {
                        printf("0 ");
                    }
                }else {
                    printf("0 ");
                }
            } else {
                if (matrix->PI[count] == j) {
                    printf("%d ", matrix->YE[count]);
                    count++;
                } else {
                    printf("0 ");
                }
            }
        }
        printf("\n");
    }
}
Matrix *matrixMultipy(Matrix *matrix1,Matrix *matrix2,m1,n1,m2,n2){
    int count = 0;
    int num = 0 ;
    int g = 0;
    Matrix * m3 = malloc(sizeof(Matrix));;
    if (n1 == m2){
        for (int i = 0; i < m1; ++i) {
            m3->CIP[i] = count;
            for (int k = 0; k < n2; ++k) {
                if (i<m1-1){
                    for (int j = matrix1->CIP[i]; j < matrix1->CIP[i+1] ; ++j) {
                        if (matrix1->PI[j] <n1 -1){
                            for (int h = matrix2->CIP[ matrix1->PI[j] ]; h < matrix2->CIP[ matrix1->PI[j]+1  ] ; ++h) {
                                if (matrix2->PI[h] == k){
                                    num += matrix2->YE[h] * matrix1->YE[j];
                                    g = 1;

                                }
                            }
                        } else{
                            int h = matrix2->CIP[ matrix1->PI[j] ];

                            while(matrix2->YE[h]!=0) {

                                if (matrix2->PI[h] == k) {
                                    num += matrix2->YE[h] * matrix1->YE[j];
                                    g = 1;
                                }
                                h++;
                            }
                        }

                    }
                }else{
                    int j = matrix1->CIP[i];
                    while(matrix1->YE[j]!=0){
                        if (matrix1->PI[j] <n1 -1){
                            for (int h = matrix2->CIP[ matrix1->PI[j] ]; h < matrix2->CIP[ matrix1->PI[j]+1  ] ; ++h) {
                                if (matrix2->PI[h] == k){
                                    num += matrix2->YE[h] * matrix1->YE[j];
                                    g = 1;

                                }
                            }
                        } else{
                            int h = matrix2->CIP[ matrix1->PI[j] ];

                            while(matrix2->YE[h]!=0) {

                                if (matrix2->PI[h] == k) {
                                    num += matrix2->YE[h] * matrix1->YE[j];
                                    g = 1;
                                }
                                h++;
                            }
                        }

                        j++;
                    }
                }

                m3->PI[count] = k;
                m3->YE[count] = num;

                if (g == 1){
                    count ++;
                }
                g = 0;
                num = 0;

            }


        }

    }
    return m3;



}
void chechDiag(Matrix *matrix){
    int i =0;
    int diag = 0;
    while (matrix->YE[i]!=0){
        if (matrix->CIP[i]!=matrix->PI[i]){
            diag = 1;
            break;
        }
        i++;

    }
    if(diag==0)
        printf("матрица диагональная");
    else
        printf("матрица не диагональная");





}