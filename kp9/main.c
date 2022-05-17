#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "funcs.h"

void swap(data_st *a, data_st*b) {
    data_st temp = *a;
    *a = *b;
    *b = temp;
}

//O(n^(3/2))
void shell_sort(data_st data[256], int input_size, int reversed) { // 1: min -> ... -> max | -1: max -> ... -> min
    int step = input_size / 2;
    while (step >= 0) {
        for (int i = 0; i + step < input_size; ++i) {
            int ind = i + step;
            while(ind >= i + step && data[ind].key * reversed < data[ind - step].key * reversed) {
                swap(&data[ind - step], &data[ind]);
                ind -= step;
            }
        }
        step--;
    }
}


void print_struct(data_st data[256], int input_size) {
    for (int i = 0; i < input_size; ++i)
        printf("%d %s", data[i].key, data[i].value);
}


void vector_shuffle(data_st data[256], int input_size) {
    long long step = time(NULL) % 4 + 1;
    for (long long i = step; i < input_size; ++i) {
        long long ind = i;
        while (ind >= step) {
            swap(&data[ind - step], &data[ind]);
            ind -= step;
        }
    }

    step = (time(NULL) / 83 * 56 + 215) % 2 + 1;
    for (long long i = step; i < input_size; ++i) {
        long long ind = i;
        while (ind >= step) {
            swap(&data[ind - step], &data[ind]);
            ind -= step;
        }
    }

    step = (time(NULL) / 15 * 9 + 20) % 3 + 1;
    for (long long i = step; i < input_size; ++i) {
        long long ind = i;
        while (ind >= step) {
            swap(&data[ind - step], &data[ind]);
            ind -= step;
        }
    }
}

int main() {
    FILE * values;
    values = fopen("input.values", "r");
    if (values == NULL) {
        printf("Невозможно открыть файл\n");
        exit(1);
    }


    int size = 10;
    data_st data[size];
    int input_size = 0;
    while (input_size!= size) {
        fscanf(values, "%d %[^\n]" ,&data[input_size].key,data[input_size].value);
        input_size++;
    }
    print_table(data,size);
    printf(" \n");
    check_sort(data,size);
    printf(" \n");
    heapSort(data,10,-1);
    print_table(data,size);
    printf(" \n");
    check_sort(data,size);
    printf(" \n");

    fclose(values);

}