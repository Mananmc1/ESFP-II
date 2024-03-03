#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[50];
    char clas[20];
    char semester[20];
    char subject[50];
    int examFee;
};
int main() {
    int n;
    printf("Enter how many records you want to store: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(sizeof(struct Student));

    printf("Enter student records (rollno name class semester subject examFee):\n");
    for (int i = 0; i < n; i++) {
        int duplicate = 0;
        do {
            duplicate = 0;
            scanf("%d %s %s %s %s %d", &students[i].rollno, students[i].name, students[i].clas, students[i].semester, students[i].subject, &students[i].examFee);
            for (int j = 0; j < i; j++) {
                if (students[j].rollno == students[i].rollno) {
                    printf("Duplicate ID found! Please enter the information again.\n");
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);
    }

    printf("=====================Output of student information============\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].clas, students[i].semester, students[i].subject, students[i].examFee);
    }

    int choice;
    printf("Choose search option:\n");
    printf("1. Search by ID\n2. Search by Name\n3. Search by Class\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int searchId;
            printf("Enter the ID to search: ");
            scanf("%d", &searchId);
            printf("Find the student record by ID:\n");
            for (int i = 0; i < n; i++) {
                if (strcmp(students[i].rollno ,searchId)) {
                    printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].clas, students[i].semester, students[i].subject, students[i].examFee);
                    break;
                }
            }
            break;
        }
        case 2: {
            char searchName[50];
            printf("Enter the name to search: ");
            scanf("%s", searchName);
            printf("Find the student record by name:\n");
            for (int i = 0; i < n; i++) {
                if (strcmp(students[i].name, searchName) == 0) {
                    printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].clas, students[i].semester, students[i].subject, students[i].examFee);
                    break;
                }
            }
            break;
        }
        case 3: {
            char searchClass[20];
            printf("Enter the class to search: ");
            scanf("%s", searchClass);
            printf("Find the student record by class:\n");
            for (int i = 0; i < n; i++) {
                if (strcmp(students[i].clas, searchClass) == 0) {
                    printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].clas, students[i].semester, students[i].subject, students[i].examFee);
                }
            }
            break;
        }
        default:
            printf("Invalid choice\n");
    }

    free(students);

    return 0;
}

