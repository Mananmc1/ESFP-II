#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct Student {
    int rollno;
    char name[50];
    int std;    
	char sem[5];
    char subject[50];
    int fee;
};
int main() {
    int n;
    printf("Enter how many records you want to store: ");
    scanf("%d", &n);
    struct Student *records = (struct Student *)malloc(n* sizeof(struct Student));
    printf("Enter rno, name, std, sem, subject and fee:\n");
	for (int i = 0; i < n; i++) {
        int duplicate = 0;
        do {
            duplicate = 0;
            scanf("%d %s %s %s %s %d", &records[i].rollno, records[i].name,& records[i].std, records[i].sem, records[i].subject, &records[i].fee);
            for (int j = 0; j < i; j++) {
                if (records[j].rollno ==records[i].rollno) {
                    printf("Duplicate ID found! Please enter the information again.\n");
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);
    }

    printf("========== Output of student information============\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
               records[i].sem, records[i].subject, records[i].fee);
    }
    char choice;
    printf("Do you want to modify / update records (Y/N)? ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        int updateChoice;
        printf("How do you want to modify record by ID or by name:\n");
        printf("Press <1> for by ID and press <2> for by name ? ");
        scanf("%d", &updateChoice);
        if (updateChoice == 1) {
            int id;
            printf("Enter student ID: ");
            scanf("%d", &id);
            for (int i = 0; i < n; i++) {
                if (records[i].rollno == id) {
                    printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
                           records[i].sem, records[i].subject, records[i].fee);
                    printf("Enter rno, name, std, sem, subject and fee:\n");
                    scanf("%d %s %d %s %s %d", &records[i].rollno, records[i].name, &records[i].std,
                          records[i].sem, records[i].subject, &records[i].fee);
                    printf("Record updated successfully\n");
                    for (int i = 0; i < n; i++) {
        					printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
               				records[i].sem, records[i].subject, records[i].fee);
    }
                    break;
                }
            }
        } else if (updateChoice == 2) {
            char searchName[50];
            printf("Enter student name to update: ");
            scanf("%s", searchName);
            for (int i = 0; i < n; i++) {
                if (strcmp(records[i].name, searchName) == 0) {
                    printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
                           records[i].sem, records[i].subject, records[i].fee);
                    printf("Enter rno, name, std, sem, subject and fee:\n");
                    scanf("%d %s %d %s %s %d", &records[i].rollno, records[i].name, &records[i].std,
                          records[i].sem, records[i].subject, &records[i].fee);
                    printf("Record updated successfully\n");
                    for (int i = 0; i < n; i++) {
			        printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
			               records[i].sem, records[i].subject, records[i].fee);
    }
                    break;
                }
            }
        } else {
            printf("Invalid choice!\n");
        }
    }
    printf("Do you want to delete (Y/N)? ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        int deleteChoice;
        printf("How do you want to delete record by ID or by name:\n");
        printf("Press <1> for by ID and press <2> for by name ? ");
        scanf("%d", &deleteChoice);
        if (deleteChoice == 1) {
            int id;
            printf("Enter student ID to delete: ");
            scanf("%d", &id);
            for (int i = 0; i < n; i++) {
                if (records[i].rollno == id) {
                    printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
                           records[i].sem, records[i].subject, records[i].fee);
                    for (int j = i; j < n - 1; j++) {
                        records[j] = records[j + 1];
                    }
                    n--;
                    printf("Record deleted successfully\n");
                    for (int i = 0; i < n; i++) {
        				printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
               			records[i].sem, records[i].subject, records[i].fee);
    					}
                    break;
                }
            }
        } else if (deleteChoice == 2) {
            char searchName[50];
            printf("Enter student name to delete: ");
            scanf("%s", searchName);
            for (int i = 0; i < n; i++) {
                if (strcmp(records[i].name, searchName) == 0) {
                    printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
                           records[i].sem, records[i].subject, records[i].fee);
                    for (int j = i; j < n - 1; j++) {
                        records[j] = records[j + 1];
                    }
                    n--;
                    printf("Record deleted successfully\n");
                    for (int i = 0; i < n; i++) {
			        printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
			               records[i].sem, records[i].subject, records[i].fee);
			    }
                    break;
                }
            }
        } else {
            printf("Invalid choice!\n");
        }
    }
    printf("========== Output of student information============\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
               records[i].sem, records[i].subject, records[i].fee);
    }
    char searchName[50];
    printf("Find the student record by name:\n");
    printf("Enter student name: ");
    scanf("%s", searchName);
    for (int i = 0; i < n; i++) {
        if (strcmp(records[i].name, searchName) == 0) {
            printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
                   records[i].sem, records[i].subject, records[i].fee);
            break;
        }
    }
    free(records);
    printf("========== Output of student information============\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %s %s %d\n", records[i].rollno, records[i].name, records[i].std,
               records[i].sem, records[i].subject, records[i].fee);
    }
    free(records);
    return 0;
}
