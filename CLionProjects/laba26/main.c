
#include "stack.h"


int main() {


    int n,m;
    // reset random
    int stime;
    long ltime;
    ltime = time (NULL);
    stime = (unsigned int) ltime/2;
    srand(stime);


    printf("вв-те размер стеков 1 и 2: ");
    scanf("%d",&n);
    scanf("%d",&m);


    Stack *s1 = stack_create(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        stack_push(s1,rand() % 20);
    }

    printf("стэк 1:\n");
    stack_print(s1);



    Stack *s2 = stack_create(sizeof(int)*m);
    for (int i = 0; i < m; i++) {
        stack_push(s2,rand() % 20);
    }
    printf("\n");
    printf("стэк 2:\n");
    stack_print(s2);




    stack_concat(s1,s2);
    printf("\n");
    printf("соединенный стек 1 со стеком 2:\n");
    stack_print(s1);

    printf("\n");
    printf("отсортированный соединенный стек:\n");
    stack_quickSort(s1,0,s1->size-1);
    stack_print(s1);




    return 0;
}
