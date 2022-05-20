#include "tree.h"
#include "transform.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void swap(char elem1,char elem2){
    char temp = elem1;

    elem1 =elem2;
    elem2 = temp;
}

void sort_sum(Tree t,Tree current,char min,Tree tree_max){
    printf("slatt");

    if (current->left->node.data.variable_name >'+' ){
        if (current->right->node.data.variable_name > min)
        {
            min = current->right->node.data.variable_name;
            tree_max = current;
        }
        if (current->left->node.data.variable_name > min)
        {
            min = current->left->node.data.variable_name;
            tree_max = current;
        }
        printf("%c",min);
        // swap( t->right->node.data.variable_name,tree_max->right->node.data.variable_name)
        char temp = t->right->node.data.variable_name;
        t->right->node.data.variable_name = tree_max->right->node.data.variable_name;
        tree_max->right->node.data.variable_name = temp;

    } else{

        char elem = current->right->node.data.variable_name;

        if (elem > min)
        {
            min = elem;
            tree_max = current;

        }
        sort_sum(t, current->left, min,tree_max);

    }



}
void tree_sort(Tree t){
    printf("slatt");

    if (t->left->node.data.variable_name >'+' && t->left->node.data.variable_name >'+' )
    {
        if (t->left->node.data.variable_name > t->right->node.data.variable_name )
        {
            char temp = t->left->node.data.variable_name;

            t->left->node.data.variable_name =t->right->node.data.variable_name;
            t->right->node.data.variable_name = temp;
            printf("\n%c",t->left->left->node.data.variable_name);

        }

    } else {
        sort_sum(t,t,'a',t);
        tree_sort(t->left);
    }


}
void check_mult_sum(Tree t,int depth, char c,Tree begin){
    printf("slatt");

    if (t->left->node.data.variable_name <= '+' && t->right->node.data.variable_name <='+')
    {

        check_mult_sum(t->left,depth,t->node.data.variable_name,t);
        check_mult_sum(t->right,depth,t->node.data.variable_name,t);

    } else{
        if (t->node.data.variable_name != begin->node.data.variable_name )
        {

            check_mult_sum(t->left,0,t->node.data.variable_name,t);

        } else  {
            if (t->left->node.data.variable_name >'+')
            {
                tree_sort(t);
            } else{
                check_mult_sum(t->left,depth++,t->node.data.variable_name,begin);

            }

        }

    }



}

