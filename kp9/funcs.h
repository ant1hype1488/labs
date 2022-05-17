//
// Created by владислав трофимов on 16.05.2022.
//

#ifndef KP9_FUNCS_H
#define KP9_FUNCS_H


typedef struct data_st
{
    int key;
    char value[256];
} data_st;
void heapSort(data_st *numbers, int array_size,int direct);
void print_table(data_st *data,int size);
void check_sort(data_st *data,int size);
#endif //KP9_FUNCS_H
