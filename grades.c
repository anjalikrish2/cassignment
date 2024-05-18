


#include <stdio.h>
#include<stdlib.h>
#include "grades.h"
#include <string.h>

char calculateGrade(float marks) {
    if (marks >= 90)
        return 'S';
    else if (marks >= 80)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 50)
        return 'D';
    else if (marks >= 40)
        return 'E';
    else
        return 'F';
}

void enterMarks(struct Student *students, int *numofstud) {
    int i, j, k;

    for (i = *numofstud; i < 10; i++) {
        printf("\nEnter name of student %d (or enter '0' to return to the menu): ", i + 1);
        scanf("%s", students[i].name);
        if (students[i].name[0] == '0')
            break;

        printf("\nEnter SRN of student %d: ", i + 1);
        scanf("%s", students[i].srn);

        printf("\nEnter phone number of student %d: ", i + 1);
        scanf("%s", students[i].numba);
        
        
        

        for (j = 0; j < 3; j++) {
            printf("Enter marks for student %d in exam %d:\n", i + 1, j + 1);
            for (k = 0; k < 5; k++) {
                printf("Enter marks for subject %d: ", k + 1);
                scanf("%f", &students[i].marks[j][k]);
            }
        }
        (*numofstud)++;
    }
}

void displayGradeCard(struct Student *students, int numofstud) {
    int i, j, k;

    printf("\nGrade Card:\n");
    for (i = 0; i < numofstud; i++) {
        printf("\n------------------------------------\n");
        printf("\nName: %s", students[i].name);

        printf("\nSRN is %s", students[i].srn);

        printf("\nPHONE NUMBER IS:%s", students[i].numba);
        

        printf("\n-------------------------------------\n");
        for (j = 0; j < 3; j++) {
            printf("\n************************************  \n");
            printf("  Exam %d:\n", j + 1);
            printf("\n************************************  \n");

            for (k = 0; k < 5; k++) {
                printf("Subject %d: %.2f\t Grade: %c\n   ", k + 1, students[i].marks[j][k], calculateGrade(students[i].marks[j][k]));
            }
        }   printf("------------------------------------\n");
    }
}
void saveToFile(struct Student *students, int numofstud, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    if (fwrite(&numofstud, sizeof(int), 1, file) != 1) {
        perror("Error writing number of students");
        fclose(file);
        return;
    }

    if (fwrite(students, sizeof(struct Student), numofstud, file) !=(size_t) numofstud) {
        perror("Error writing student data");
        fclose(file);
        return;
    }

    fclose(file);
    printf("Data successfully saved to %s\n", filename);
}

void loadFromFile(struct Student *students, int *numofstud, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    if (fread(numofstud, sizeof(int), 1, file) != 1) {
        perror("Error reading number of students");
        fclose(file);
        return;
    }

    if (fread(students, sizeof(struct Student), *numofstud, file) !=(size_t) *numofstud) {
        perror("Error reading student data");
        fclose(file);
        return;
    }

    fclose(file);
    printf("Data successfully loaded from %s\n", filename);
}
void searchBySRN(struct Student *students, int numofstud, const char *srn) {
    int i, j, k;
    for (i = 0; i < numofstud; i++) {
        if (strcmp(students[i].srn, srn) == 0) {
            printf("\n------------------------------------\n");
            printf("\nName: %s", students[i].name);
            printf("\nSRN: %s", students[i].srn);
            printf("\nPhone Number: %s", students[i].numba);
            printf("\n-------------------------------------\n");

            for (j = 0; j < 3; j++) {
                printf("\n************************************\n");
                printf("Exam %d:\n", j + 1);
                printf("************************************\n");

                for (k = 0; k < 5; k++) {
                    printf("Subject %d: %.2f\t Grade: %c\n", k + 1, students[i].marks[j][k], calculateGrade(students[i].marks[j][k]));
                }
            }
            return;
        }
    }
    printf("Student with SRN %s not found.\n", srn);
}

