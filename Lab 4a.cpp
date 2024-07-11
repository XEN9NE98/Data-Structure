#include <stdio.h>
#include <stdlib.h>

struct employee {
	int empID, age;
	char firstName[100], lastName[100];
	float salary;
	struct employee *next;
};

struct employee *head = NULL;

void insertRecord(){
	struct employee *newEmp = (struct employee*) malloc (sizeof(struct employee));
	
	if (newEmp == NULL){
		printf("\n  Memory Allocation Error!");
		return;
	}
	
	printf("\n  Create New Record""\n  Please enter new employee details\n\n");
	printf("  Enter Employee ID : ");
	scanf(" %d", &newEmp->empID);
	printf("  Enter First Name  : ");
	scanf(" %s", newEmp->firstName);
	printf("  Enter Last Name   : ");
	scanf(" %s", newEmp->lastName);
	printf("  Enter Age         : ");
	scanf(" %d", &newEmp->age);
	printf("  Enter Salary      : ");
	scanf(" %f", &newEmp->salary);
	
	newEmp->next = NULL;
	
	if (head == NULL){
		head = newEmp;
	} else {
		newEmp->next = head;
		head = newEmp;
	}
	printf("\n  New record created successfully");
	return;
}

void deleteRecord(){
	int deleteID;
	struct employee *temp = head, *afterTemp = NULL;
	
	printf("\n  Delete Exisiting Record\n");
	printf("\n  Enter Employee ID: ");
	scanf("%d", &deleteID);
	
	while (temp != NULL && temp->empID != deleteID){
		afterTemp = temp;
		temp = temp->next;
	}
	
	if (temp == NULL){
		printf("\n  Record for ID: %d is not found!", deleteID);
		return;
	}
	
	if (temp == head){
		head = temp->next;
	} else {
		afterTemp->next = temp->next;
	}
	free(temp);
	printf("\n  Record for ID: %d deleted successfully", deleteID);
	return;
}

void viewRecord(){
	struct employee *printPointer = head;
	int count = 1;
	
	printf("\n  View Latest Record\n");
	
	if (printPointer == NULL){
		printf("\n  Record is Empty\n");
		return;
	}
	
	while (printPointer != NULL){
		printf("\n  Record #%d:", count);
		printf("\n  Employee ID : %d", printPointer->empID);
		printf("\n  First Name  : %s", printPointer->firstName);
		printf("\n  Last Name   : %s", printPointer->lastName);
		printf("\n  Age         : %d", printPointer->age);
		printf("\n  Salary      : RM%.2f\n", printPointer->salary);
		count++;
		printPointer = printPointer->next;
	}
	return;
}

int main(){
	int input;
	
	while (1){
		printf("\n\n  + ----- Employee Record Management System ----- +"
		"\n  |                                               |"
		"\n  | 1 > Create New Record                         |"
		"\n  | 2 > Delete Existing Record                    |"
		"\n  | 3 > Display Latest Record                     |"
		"\n  | 4 > End Program                               |"
		"\n  |                                               |"
		"\n  + --------------------------------------------- +"
		"\n\n  ? > ");
		scanf("%d", &input);
		
		switch(input){
			case 1:
				insertRecord();
				break;
			case 2:
				deleteRecord();
				break;
			case 3:
				viewRecord();
				break;
			case 4:
				return 0;
			default:
				printf("\n  Invalid Input!");
				break;
		}
	}
}
