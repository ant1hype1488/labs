#include <stdio.h>
#include "funcs.h"
#include "stack.c"
#include "time.h"
#include <stdio.h>

int main() {
    int n = 5;
    int stime;
    long ltime;
    Stack *s1 = stack_create(sizeof(int)*n);
    Stack *s2 = stack_create(sizeof(int)*n);
    ltime = time (NULL);
    stime = (unsigned int) ltime/2;
    srand(stime);
    for (int i = 0; i < n; i++) {
        stack_push(s1,rand() % 20);
    }
    for (int i = 0; i < n; i++) {
        stack_push(s2,rand() % 20);
    }
    stack_join(s1,s2);
    stack_print(s1);
    stack_hoare_sort(s1);
    printf("\n");
    stack_print(s1);





    return 0;
}
