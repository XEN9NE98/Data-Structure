#include <stdio.h> 
#include <stdlib.h>

// Declare size of the array
#define SIZE 5 

int top = -1; 
int stack[SIZE]; 

// Push new data into the stack
void push(){ 
    int input;
    // If stack is full display error
    if (top == SIZE - 1){ 
       printf("\nStack Overflow\n");  
    } else {
    // Else request input and push the new data
        printf("Insert Number: "); 
        scanf("%d",&input); 
        top = top + 1; 
        stack[top] = input;  
    } 
} 

// Pop the data out
void pop(){ 
    // If the stack empty, display error
    if(top == -1){ 
        printf("Stack Underflow!\n"); 
    } else { 
        // Else pop the latest data
        printf("Delete the element %d", stack[top]); 
        top = top - 1; 
    } 
} 

// Display the content of the stack
void show(){ 
    // If the stack empty, display error
    if(top == -1){ 
        printf("Stack is empty!\n"); 
    } else { 
        // Else, print stack content
        for(int x = top; x >= 0; --x){ 
            printf("%d\n", stack[x]); 
        } 
    } 
} 

int main(){
    // Display the main menu
    while(1){ 
        int choice; 
        printf("\nPerform operations on the stack:"); 
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End"); 
        printf("\n\nEnter the choice: "); 
        scanf("%d", &choice);

        switch(choice){ 
            case 1: 
                // Go the push() function
                push(); 
                break; 
            case 2: 
                // Go the pop() function
                pop(); 
                break; 
            case 3: 
                // Go the show() function
                show(); 
                break; 
            case 4:
                // Exit program
                return 0; 
            default: 
                // Display error message
                printf("Invalid choice "); 
                break; 
        } 
    } 
} 
