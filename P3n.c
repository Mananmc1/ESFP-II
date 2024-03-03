#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct records {
    int id;
    char name[20];
    int qty;
    float price;
    float tpri;
    struct records* next;
};
struct records* start;
struct records* end;
int addRecord() {
    struct records* temp;
    temp = (struct records*)malloc(sizeof(struct records));
    printf("Enter PID, Pname, Pqty, Pprice: ");
    scanf("%d %s %d %f", &temp->id, temp->name, &temp->qty, &temp->price);
    temp->tpri = temp->qty * temp->price;
    if (start == NULL) {
        temp->next = NULL;
        start = temp;
        end = temp;
    } else {
        end->next = temp;
        end = temp;
        end->next = NULL;
    }
    return 0;
}
int displayRecords() {
    struct records* ptr;
    if (start == NULL) {
        printf("List is blank\n");
    } else {
        printf("=========== Purchased Output Product Information =============\n");
        printf("PID PName PQty Pprice PTprice\n");
        for (ptr = start; ptr != NULL; ptr = ptr->next) {
            printf("%d %s %d %f %f\n", ptr->id, ptr->name, ptr->qty, ptr->price, ptr->tpri);
        }
    }
    return 0;
}
int searchRecord() {
    char choice;
    int searchId;
    char searchName[20];
    printf("Do you want to find individual product information (y/n)?: ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
       int searchOption;
       printf("How do you want to find product information by ID or by Name: 1 for ID and 2 forName:");
        scanf("%d", &searchOption);
        if (searchOption == 1) {
            printf("Enter product Id: ");
            scanf("%d", &searchId);
        } else if (searchOption == 2) {
            printf("Enter product Name: ");
            scanf("%s", searchName);
        } else {
            printf("Invalid option\n");
            return 0;
        }
        struct records* ptr = start;
        printf("PID PName PQty Pprice PTprice\n");
        while (ptr != NULL) {
            if ((searchOption == 1 && ptr->id == searchId) || (searchOption == 2 && strcmp(ptr->name,
                 searchName) == 0)) {
                printf("%d %s %d %f %f\n", ptr->id, ptr->name, ptr->qty, ptr->price, ptr->tpri);
                break;
            }
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            printf("Product not found\n");
        }
    }
}
int deleteRecord() {
    char choice;
    int deleteId;
    char deleteName[20];
    printf("Do you want to delete product record (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        int deleteOption;
        printf("How do you want to delete record by ID or By name? 1 for by ID and 2 for by Name: ");
        scanf("%d", &deleteOption);
        if (deleteOption == 1) {
            printf("Enter Product ID: ");
            scanf("%d", &deleteId);
        } else if (deleteOption == 2) {
            printf("Enter Product Name: ");
            scanf("%s", deleteName);
        } else {
            printf("Invalid option\n");
            return 0;
        }
        struct records* current = start;
        struct records* prev = NULL;
        while (current != NULL) {
            if ((deleteOption == 1 && current->id == deleteId) || (deleteOption == 2 && 
            strcmp(current->name, deleteName) == 0)) {
                if (prev == NULL) {
                    start = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("============= Updated Record ============\n");
                displayRecords();
                break;
            }
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("Product not found\n");
        }
    }
}
int main() {
    int choice;
    do {
        printf("\n1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice, please enter again.\n");
        }
    } while (choice != 5);
    return 0;
}