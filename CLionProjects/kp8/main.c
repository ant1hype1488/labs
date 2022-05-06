#include "funcs.h"



int main(void){
    list *a = init("word");
    add(a,"slatt");
    add(a,"letsgoo");
    add(a,"opium");
    add(a,"sssss");
    printf("\n");
    swap(a);
    listprint(a);
    printf("\n");
    listprintBack(a);


    return 0;
}