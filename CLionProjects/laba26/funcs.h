//
// Created by владислав трофимов on 06.05.2022.
//

#ifndef LABA26_FUNCS_H
#define LABA26_FUNCS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "time.h"

typedef int Item;

typedef struct stacknode {
    Item data;
    struct stacknode *next;
} StackNode;

typedef struct {
    StackNode *head;
    int size;
} Stack;

void stack_hoare_sort(Stack *s);
Stack *stack_create(size_t stack_size);
void stack_print(Stack *s);
void stack_push(Stack *s, Item value);
Item stack_pop(Stack *s);
void stack_concat(Stack *s1,Stack *s2);
bool stack_is_empty(Stack *s);
void setElemByIndex(Stack *s,int i ,int value);
void stack_destroy(Stack *s);
int getElemByIndex(Stack *s,int i);
void stackElemsSwap(Stack *s,int i ,int j);
void stack_quickSort(Stack *s, int low, int high);

#endif //LABA26_FUNCS_H
