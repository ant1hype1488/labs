#include "funcs.h"


list * init(char word[50]) // а- значение первого узла
{
    list *lst;
    // выделение памяти под корень списка
    lst = ( list*)malloc(sizeof( list));
    strcpy(lst->field,word);
    lst->next = lst; // это последний узел списка
    lst->prev = lst;
    lst->i = 0;
    return(lst);

}


void add(list *lst, char word[50])
{
    list *temp = lst;

    while (temp->next!=lst)
    {
        temp = temp->next;
    }

    temp->next = (list*)malloc(sizeof(list));
    strcpy(temp->next->field,word );
    temp->next->i = temp->i + 1;
    temp->next->prev = temp;
    temp->next->next =  lst;
    lst->prev =  temp->next;



}
void listprint(list *lst)
{
    list *p;
    p = lst;
    do {
        printf("%s ", p->field); // вывод значения элемента p
        p = p->next; // переход к следующему узлу
    } while (p != lst);
}
void listprintBack(list *lst)
{
    list *p;
    p = lst->prev;
    do {
        printf("%s ", p->field); // вывод значения элемента p
        p = p->prev; // переход к следующему узлу
    } while (p != lst->prev);
}

void swap(list *lst){
    if(lst->prev->i>3){
        list *second = lst->next;
        list *penultimate = lst->prev->prev;
        char tmp[50];

        strcpy(tmp,second->field);
        strcpy(second->field,penultimate->field);
        strcpy(penultimate->field,tmp);

    }

}





