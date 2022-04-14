#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

typedef struct {
    int ptr;
    Item *data;
} Stack;

Stack *stack_create(size_t stack_size);

void stack_push(Stack *s, Item value);
void stack_concat(Stack *stack1, Stack *stack2);
void stack_print(Stack *stack);
Item stack_pop(Stack *s);
Item stack_peak(Stack *s);
bool stack_is_empty(Stack *s);

void stack_destroy(Stack *s);

#endif