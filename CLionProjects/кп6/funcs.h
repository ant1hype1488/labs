
#ifndef KP6_FUNCS_H
#define KP6_FUNCS_H
typedef struct
{

    char family[20];
    char sign[10];
    char sex[5];
    int group;
    int grades[3];


    // char *family;


} Students;

void addStudent();
void showStudents();
void randomStudents(int n);
void bestStudents();

#endif //KP6_FUNCS_H