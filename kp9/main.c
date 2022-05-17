#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "funcs.h"







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