#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcs.h"




void bestStudents(){
    FILE *fptr;

    Students student;
    int groupCount = 0;
    int max = 0;
    int p;
    int exist = 0;
    int *groups;

    int n = 0;
    Students *all = (Students*)malloc(n*sizeof(Students));
    if ((fptr = fopen("data.bin","rb")) == NULL){
        exit(1);
    }

    while (fread(&student, sizeof(Students), 1, fptr)==1)
    {
        n++;
        all = (Students *)realloc(all, sizeof(Students) * n);
        *(all+n-1) = student;
    }
    fclose(fptr);
    for (int i = 0; i < n; ++i) {
        if (groupCount == 0) {
            groupCount = 1;
            groups = (int*) malloc(sizeof(int)*groupCount);
            *(groups + groupCount-1) = all[i].group;
            for (int j = 0; j < n; ++j) {
                if (all[j].group == all[i].group){
                    if ((all[j].grades[0] + all[j].grades[1]+ all[j].grades[2] > max) &&all[j].grades[0] >= 4 && all[j].grades[1] >= 4&& all[j].grades[2] >= 4) {
                        max = all[j].grades[0] + all[j].grades[1]+ all[j].grades[2];
                        p = j;
                    }
                }
            }
            if (max!=0) {
                printf("Лучший студент группы %d - %s\n", all[p].group, all[p].family);
                max = 0;
            }

        } else{
            for (int j = 0; j < groupCount; ++j) {
                if (all[i].group ==  groups[j]){
                    exist = 1;
                }
            }
            if (exist == 0){

                groupCount ++;

                groups = (int *)realloc(groups, groupCount * sizeof(int));
                *(groups + groupCount -1) = all[i].group;
                for (int j = 0; j < n ; ++j) {
                    if ( all[j].group ==  all[i].group){
                        if ((all[j].grades[0] + all[j].grades[1]+ all[j].grades[2] > max) &&all[j].grades[0] >= 4 && all[j].grades[1] >= 4&& all[j].grades[2] >= 4) {
                            max = all[i].grades[0] + all[i].grades[1]+ all[i].grades[2];
                            p = j;
                        }
                    }
                }
                if (max!=0) {
                    printf("лучший студент группы %d - %s\n", all[p].group, all[p].family);
                    max = 0;

                }
            } else{
                exist = 0;

            }
        }
    }
    free(groups);
}
