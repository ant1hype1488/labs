

#include "stack.h"

Stack *stack_create(size_t stack_size)
{
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;

    return s;
}

StackNode *insert_stack_node(StackNode *parent, Item value)
{
    StackNode *new_node = (StackNode *) malloc(sizeof(StackNode));

    new_node->data = value;
    new_node->next = parent;

    return new_node;
}

void stack_push(Stack *s, Item value)
{
    s->head = insert_stack_node(s->head, value);
    s->size++;
}

void node_add(Stack *s1, StackNode *s2){


    if (s2->next !=NULL){
        node_add(s1,s2->next);
    }

    StackNode *new_node = (StackNode *) malloc(sizeof(StackNode));

    new_node->data = s2->data;
    new_node->next = s1->head;
    s1->size++;
    s1->head = new_node;


}

void stack_concat(Stack *a, Stack *b)
{
    node_add(a,b->head);
}

void node_print(StackNode *node){
    if (node->next !=NULL){
        node_print(node->next);
    }
    printf("%d ",node->data);

}


void stack_print(Stack *s){
    node_print(s->head);
    printf("\n");


}


Item stack_pop(Stack *s)
{
    Item data = s->head->data;

    StackNode *tmp = s->head->next;
    free(s->head);
    s->head = tmp;
    s->size--;
    return data;
}

bool stack_is_empty(Stack *s)
{
    return (s->head == NULL);
}

void stack_destroy(Stack *s)
{
    while (!stack_is_empty(s))
        stack_pop(s);

}





void setElemByIndex(Stack *s,int i ,int value){
    Stack *temp = stack_create(sizeof(int)*s->size);

    for (int j = 0; j < i; j++)
    {
        int elem = stack_pop(s);
        stack_push(temp,elem);
    }

    s->head->data = value;

    for (int j = 0; j < i; j++)
    {
        int elem = stack_pop(temp);
        stack_push(s,elem);
    }
    stack_destroy(temp);



}
int getElemByIndex(Stack *s,int i){
    Stack *temp = stack_create(sizeof(int)*s->size);


    for (int j = 0; j < i; j++)
    {
        int elem = stack_pop(s);
        stack_push(temp,elem);
    }
    int value = s->head->data;
    for (int j = 0; j < i; j++)
    {
        int elem = stack_pop(temp);
        stack_push(s,elem);
    }
    stack_destroy(temp);
    return value;
}


int stack_partition(Stack *s, int low, int high)
{
    int pivot = getElemByIndex(s,high);
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (getElemByIndex(s,j) >= pivot)
        {
            i++;


            stackElemsSwap(s,j,i);
        }
    }
    stackElemsSwap(s,high,i+1);

    return (i + 1);
}
void stack_quickSort(Stack *s, int low, int high)
{
    if (low < high)
    {
        int pi = stack_partition(s, low, high);


        stack_quickSort(s, low, pi - 1);
        stack_quickSort(s, pi + 1, high);
    }
}
void stackElemsSwap(Stack *s,int i ,int j){
    int temp = getElemByIndex(s,i);
    setElemByIndex(s,i,getElemByIndex(s,j));
    setElemByIndex(s,j,temp);
}