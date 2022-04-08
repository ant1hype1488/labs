#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcs.h"
#include <time.h>

void randomStudents(int n){
    FILE *fptr;
    Students student;
    int stime;
    long ltime;
    char sign1[3];
    char sign2[3];

    char names[][20] = {
            "Vlad",
            "Vladislav",
            "Trofimov",
            "Ilya",
            "Vlad Trofimov",
            "Murad Ahab",
            "Gudok Slatt",
            "Playboi Carti",
            "Lil Uzi Vert",
            "Vitalik Buterin",
            "Zamay",
            "Gnoyniy",
            "Sonya Marmevadoda",
            "Verhovenskiy",
            "Myshkin",
            "Kunteynir",
            "Putin",
            "Velikiy",
            "Moses",
            "Django"
    };
    if ((fptr = fopen("data.bin","wb")) == NULL){
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    ltime = time (NULL);
    stime = (unsigned int) ltime/2;
    srand(stime);
    for (int i = 0; i < n; ++i) {
        student.group = 100 + rand()%9;
        int nameNum = rand()%20;
        strcpy(student.family,names[nameNum]);
        sign1[0]= names[nameNum][rand()%4];
        sign1[1]='\0';
        sign2[0]= names[nameNum][rand()%4];
        sign2[1]='\0';


        strcpy(student.sign, strcat(sign1,sign2));
        if (rand()%2 == 1){
            strcpy(student.sex,"m");
        } else{
            strcpy(student.sex,"w");
        }

        student.grades[0] = 1+rand()%5;
        student.grades[1] = 1+rand()%5;
        student.grades[2] = 1+rand()%5;
        fwrite(&student, sizeof(Students), 1, fptr);

    }
    fclose(fptr);
}


