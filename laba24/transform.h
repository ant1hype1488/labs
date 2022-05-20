

#ifndef LABA24_TRANSFORM_H
#define LABA24_TRANSFORM_H

#include "tree.h"

void tree_transform(Tree *t);
void tree_sort(Tree t);
void sort_sum(Tree t,Tree current,char max,Tree tree_max);
void check_mult_sum(Tree t,int depth, char c,Tree begin);
#endif //LABA24_TRANSFORM_H
