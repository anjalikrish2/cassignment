#include <stdio.h>
#include "grades.h"

int main() {
    int choice;
    int i, j, k;
    struct Student students[10];
    int numofstud = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Click '1' to Enter Marks.thanks\n");
        printf("2. Click '2' to Display Grade Card\n");
        printf("3. Click '3' to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Function to enter student data
                enterMarks(students, &numofstud);
                break;
            case 2:
                // Function to display grade card
                displayGradeCard(students, numofstud);
                break;
            case 3:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
