
#include <stdio.h>
#include "funcs.h"

int main()
{
    int n;
    int ans = 0;
    while (ans!=-1){
        printf("1.Все студенты\n2.Добавить студента\n3.Вывести лучших студентов\n4.Пересоздать таблицу\n");
        scanf("%d",&ans);
        switch (ans) {
            case 1:
                showStudents();
                break;
            case 2:
                addStudent();
                break;
            case 3:

                bestStudents();
                break;
            case 4:
                printf("Кол-во студентов: ");
                scanf("%d",&n);
                randomStudents(n);
                break;
            default:
                ans = -1;
                break;
        }
    }

    return 0;
}