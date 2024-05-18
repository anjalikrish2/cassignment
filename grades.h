

#ifndef GRADES_H
#define GRADES_H

struct Student {
    char name[50];
    char srn[12];
    char numba[15];
    float marks[3][5];
};

char calculateGrade(float marks);
void enterMarks(struct Student *students, int *numofstud);
void displayGradeCard(struct Student *students, int numofstud);
void saveToFile(struct Student *students, int numofstud, const char *filename);
void loadFromFile(struct Student *students,int *numofstud, const char *filename);
void searchBySRN(struct Student *students, int numofstud, const char *srn);

#endif

