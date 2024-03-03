#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <excpt.h>
struct records
{
    int college_id;
    char college_name[23];
    char cource_stream[20];
    int year ;
    char sem[20];
    char sub_group[23];
    int college_fees;
    struct records *next;
    struct records *prev;
};
struct records *start;
struct records *end;
struct records *temp;
void addRecord(){
    temp = (struct records*)malloc(sizeof(struct records));
    printf("Enter College_ID, College_Name, course_stream, year, semester, subject group and their fee\n");
    scanf("%d %s %s %d %s %s %d", &temp->college_id,temp->college_name,temp->cource_stream,&temp->year,temp->sem,temp->sub_group,&temp->college_fees);
    if(start==NULL){
        temp->next=NULL;
        temp->prev=NULL;
        start=temp;
        end=temp;
    }
    else{
        temp->next = NULL;
        temp->prev = end;
        end->next = temp;
        end = temp;
    }
}
void display(){
    if (start == NULL) {
        printf("List is blank\n");
    } else {
        printf("=============================Output of Student Information===========================\n");
        printf(" College_ID, College_Name, course_stream, year, semester, subject group and their fee\n");
        for(temp=end;temp!=NULL;temp=temp->prev){
        printf("%d %s %s %d %s %s %d \n", temp->college_id,temp->college_name,temp->cource_stream,temp->year,temp->sem,temp->sub_group,temp->college_fees);
        }
    }
}
void searchRecord(){
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
        }
        temp=start;
        printf("College_ID, College_Name, course_stream, year, semester, subject group and their fee\n");
        while (start!=NULL)
        {
            if ((searchOption == 1 && temp->college_id == searchId) || (searchOption == 2 && strcmp(temp->college_name,searchName) == 0)) {
                printf("%d %s %s %d %s %s %d", temp->college_id,temp->college_name,temp->cource_stream,temp->year,temp->sem,temp->sub_group,temp->college_fees);
                break;
            }
            temp=temp->next;
        }
        if (temp == NULL) {
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
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                display();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice, please enter again.\n");
        }
    } while (choice != 4);
    return 0;
}