
#include "funcs.h"


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


int partition(int *arr, int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++)
	{
	
		if (arr[j] <= pivot)
		{
			i++; 
            int temp = *(arr + i );
            *(arr + i ) =  *(arr + j);
            *(arr + j) = temp;
		}
	}

    int temp = arr[i + 1];
    *(arr + i + 1) =  arr[high];
    *(arr + high) = temp;
	return (i + 1);
}
void quickSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void stack_hoare_sort(Stack *s){
    int n = s->size;
    int *temp = (int*)malloc(sizeof(int)*n );
    for (int i = 0; i < n ; i++)
    {
        *(temp + i) = stack_pop(s);
    }
	quickSort(temp, 0, n-1);
    for (int i = 0; i < n ; i++)
    {
        s->head = insert_stack_node(s->head, temp[i]);
    }
    free(temp);
    printf("\n");
    
    
}