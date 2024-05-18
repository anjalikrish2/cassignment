#include <stdio.h>
#include "grades.h"
#define MAX_STUDENTS 10

int main() {
    struct Student students[MAX_STUDENTS];
    int numofstud = 0;
    int choice;
    char srn[12];
    const char *filename = "students.dat";
    printf("Loading data from file...\n");

    loadFromFile(students, &numofstud, filename);
    printf("Data loaded. Number of students: %d\n", numofstud);

    do {
        printf("\nMenu:\n");
        printf("1. Enter Marks\n");
        printf("2. Display Grade Card\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Search by SRN\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterMarks(students, &numofstud);
                break;
            case 2:
                displayGradeCard(students, numofstud);
                break;
            case 3:
                printf("Saving data to file...\n");
                saveToFile(students, numofstud, filename);
                break;
            case 4:
                printf("Loading data from file...\n");
                loadFromFile(students, &numofstud, filename);
                
                break;
            case 5:
                printf("Enter SRN to search: ");
                scanf("%s", srn);
                searchBySRN(students, numofstud, srn);
                break;

            case 6:
                printf("Saving data to file before exiting...\n");
                saveToFile(students, numofstud, filename);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}


