#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

void showStudents(){
    FILE *fptr;
    Students student;

    if ((fptr = fopen("data.bin","rb")) == NULL){
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    printf("Группа|\t\tФамилия                 |\tИнициалы\t|\tПол\t|\tОценка1\t|\tОценка2\t|\tОценка3\t|\n");

    while (fread(&student, sizeof(Students), 1, fptr)==1)
    {
        printf("------|-----------------------------|---------------|-------|-----------|-----------|-----------|\n");
        printf("%d   |\t\t%20s\t|%10s     |\t %s  |\t\t %d  |\t\t %d  |\t\t %d  |\n", student.group,student.family, student.sign,student.sex,student.grades[0],student.grades[1],student.grades[2]);
    }

    fclose(fptr);
}

