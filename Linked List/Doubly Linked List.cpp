// Add, Delete and Print Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
	char author[100];
	char publishDate[30];
	char title[100];
	char edition[30];
	char publisher[100];
	char callNum[100];
	struct book *next;
	struct book *prev;
};

struct book *head = NULL, *tail = NULL;

void insertRecord(){
	struct book *temp = head;
	struct book *newbook = (struct book*) malloc (sizeof(struct book));
	if (newbook == NULL){
		printf("\n  Memory Allocation Error\n");
		return;
	}
	
	printf("\n  Create New Record""\n  Please enter new book details\n\n");
	printf("  Enter Author        : ");
	scanf(" %[^\n]%*c", newbook->author);
	printf("  Enter Publish Date  : ");
	scanf(" %[^\n]%*c", newbook->publishDate);
	printf("  Enter Title         : ");
	scanf(" %[^\n]%*c", newbook->title);
	printf("  Enter Edition       : ");
	scanf(" %[^\n]%*c", newbook->edition);
	printf("  Enter Publisher     : ");
	scanf(" %[^\n]%*c", newbook->publisher);
	printf("  Enter Call Number   : ");
	scanf(" %[^\n]%*c", newbook->callNum);
	
	newbook->next = NULL;
	newbook->prev = NULL;
	
	if (head == NULL){
		head = newbook;
		tail = newbook;
	} else {
		while (temp != NULL && strcmp(temp->title, newbook->title) < 0){
			temp = temp->next;
		}
		if (temp == head){
			newbook->next = head;
			head->prev = newbook;
			head = newbook;
		} else if (temp == NULL){
			newbook->prev = tail;
			tail->next = newbook;
			tail = newbook;
		} else {
            newbook->next = temp;
            newbook->prev = temp->prev;
            temp->prev->next = newbook;
            temp->prev = newbook;
		}
	}
	printf("\n  New record created successfully");
	return;
}

void deleteRecord(){
	char deleteCall[100];
	struct book *temp = head;
	
	printf("\n  Delete Exisiting Record\n");
	printf("\n  Enter Book Call Number: ");
	scanf(" %[^\n]%*c", deleteCall);
	
	while (temp != NULL && strcmp(temp->callNum, deleteCall) != 0){
		temp = temp->next;
	}
	
	if (temp == NULL){
		printf("\n  Record not found!");
		return;
	}
	
	if (temp == head){
		head = temp->next;
		if (head != NULL){
			head->prev = NULL;
		} else {
			tail = NULL;
		}
	} else if (temp == tail) {
		tail = temp->prev;
		if (tail != NULL){
			tail->next = NULL;
		} else {
			head = NULL;
		}
	} else {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	free(temp);
	printf("\n  Record deleted successfully");
	return;
}

void viewRecord(){
	struct book *printPointer = head;
	int count = 1;
	
	printf("\n  View Latest Record\n");
	
	if (printPointer == NULL){
		printf("\n  Record is Empty\n");
		return;
	}
	
	while (printPointer != NULL){
		printf("\n  Record #%d:", count);
		printf("\n  Author        : %s", printPointer->author);
		printf("\n  Publish Date  : %s", printPointer->publishDate);
		printf("\n  Title         : %s", printPointer->title);
		printf("\n  Edition       : %s", printPointer->edition);
		printf("\n  Publisher     : %s", printPointer->publisher);
		printf("\n  Call Number   : %s\n", printPointer->callNum);
		count++;
		printPointer = printPointer->next;
	}
	return;
}

int main(){
	int input;
	
	while (1){
		printf("\n\n  + ------- Book Record Management System ------- +"
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
