#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;

void insert(int new_data){
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	if (newNode == NULL){
		printf("Memory Allocation Error");
		return;
	}
	newNode->data = new_data;
	newNode->next = NULL;
	
	if (head == NULL){
		head = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
}

// Function to merge two sorted linked lists
struct node* merge(struct node* left, struct node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Function to find the middle of the linked list
struct node* findMiddle(struct node* head) {
    if (head == NULL) return NULL;

    struct node* slow = head;
    struct node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node* middle = slow->next;
    slow->next = NULL;

    return middle;
}

// Function to perform merge sort on the linked list
struct node* mergeSort(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct node* middle = findMiddle(head);
    struct node* left = mergeSort(head);
    struct node* right = mergeSort(middle);

    return merge(left, right);
}

// Function to sort the linked list
void sort() {
    head = mergeSort(head);
}

void print(){
	struct node *printPtr = head;
	while (printPtr != NULL){
		printf("%d  ", printPtr->data);
		printPtr = printPtr->next;
	}
}

int main(){
	int arr[] = {21, 32, 2, 55, 13, 22, 45, 67, 77, 89, 102, 230, 333, 212, 121, 67, 55}, i = 0;
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	while (i < arr_size){
		insert(arr[i]);
		i++;
	}
	
	printf("Before sorting:\n");
	print();
	
	sort();
	
	printf("\n\nAfter sorting:\n");
	print();
}
