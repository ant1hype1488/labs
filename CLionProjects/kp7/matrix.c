#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#include "matrix.h"
void createMatrix(Matrix* m) {
    m = malloc(sizeof(Matrix));
}

void  inputMatrix(Matrix *matrix,int m,int n){
    int num ;
    int count =0;
    for (int i = 0; i <m ; ++i) {
        if((count  == matrix->CIP[i-1]) ){
            *(matrix->CIP + i) = 0;
        } else{
            *(matrix->CIP + i) = count;

        }
        for (int j = 0; j < n; ++j) {
            scanf("%d",&num);
            if(num !=0){
                *(matrix->PI + count) = j;
                *(matrix->YE + count) = num;
                count++;
            }

        }

    }
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