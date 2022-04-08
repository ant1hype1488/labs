#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
void addStudent(){

    FILE *fptr;
    Students student;
    scanf("%d",&student.group);
    char temp1[20];

    scanf("%s",temp1);
    strcpy(student.family,temp1);
    char temp2[20];

    scanf("%s",temp2);
    strcpy(student.sign,temp2);

    char temp3[20];
    scanf("%s",temp3);
    strcpy(student.sex,temp3);
    scanf("%d ",&student.grades[0]);
    scanf("%d",&student.grades[1]);
    scanf("%d",&student.grades[2]);
    if ((fptr = fopen("data.bin","ab")) == NULL){
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    fwrite(&student, sizeof(Students), 1, fptr);
    fclose(fptr);

}
