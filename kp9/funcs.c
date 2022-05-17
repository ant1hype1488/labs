#include "funcs.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"



void siftDown(data_st *numbers, int root, int bottom,int direct)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if ((numbers[root * 2].key > numbers[root * 2 + 1].key) && direct == 1)
            maxChild = root * 2;
        else if ((numbers[root * 2].key < numbers[root * 2 + 1].key) && direct == -1)
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (numbers[root].key < numbers[maxChild].key  && direct == 1)
        {
            data_st temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }else if ((numbers[root].key > numbers[maxChild].key)  && direct == -1)
        {
            data_st temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }else
            done = 1;
    }
}
void heapSort(data_st *numbers, int array_size,int direct)
{
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1,direct);
    for (int i = array_size - 1; i >= 1; i--)
    {
        data_st temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1,direct);
    }
}
void print_table(data_st *data,int size){
    for (int i = 0; i < size; ++i) {
        printf("%d %s\n",data[i].key,data[i].value);
    }
}

void check_sort(data_st *data,int size){
    int sortedBack = 0;
    int sorted = 0;
    for (int i = 0; i < size/2 + 1; ++i) {
        if(data[i].key >data[i+1].key ){
            sorted++;
        }
        if(data[size - 1- i].key < data[size- 2- i].key ){
            sortedBack++;
        }
    }
    if (sorted ==  size/2 + 1 && sortedBack ==  size/2 + 1){
        printf("отсортирован задом");
    }else if(sorted == 0 && sortedBack == 0 ){
        printf("отсортирован ");
    } else if(sorted!=0 || sortedBack!=0){
        printf("не отсортирован ");
    }
}
