
int main(void){
    list *a = init("word");
    add(a,"slatt");
    add(a,"letsgoo");
    add(a,"opium");
    add(a,"sssss");
    printf("before:\n");
    listprint(a);
    printf("\n");
    swap(a);
    printf("after:\n");

    listprint(a);
    printf("\n");
    listprintBack(a);


    return 0;
}