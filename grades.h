#ifndef GRADES_H
#define GRADES_H

struct Student {
    char name[30];
    char srn[3][10];
    char numba[10][10];
    float marks[3][5];
    
};

char calculateGrade(float marks);
void enterMarks(struct Student *students, int *numofstud);
void displayGradeCard(struct Student *students, int numofstud);

#endif /* GRADES_H */

