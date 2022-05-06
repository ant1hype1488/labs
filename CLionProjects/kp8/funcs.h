//
// Created by владислав трофимов on 06.05.2022.
//

#ifndef KP8_FUNCS_H
#define KP8_FUNCS_H

#include "funcs.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <string.h>


typedef int Item;

typedef struct list
{

    char field[50];
    struct list *next;
    struct list *prev;
    int i;

}list;

list * init(char *word);
void listprint(list *lst);
void add(list *lst,  char word[50]);
void swap(list *list);
void listprintBack(list *lst);

#endif //KP8_FUNCS_H
