#include <stdio.h> 
#include <stdlib.h> 

struct node{ 
    int data; 
    struct node *next; 
} *top = NULL; 

void push(int input){ 
    struct node *new_node = NULL; 
    new_node = malloc(sizeof(struct node)); 
    if (new_node == NULL){ 
        printf("Stack Overflow!\n"); 
        return; 
    }

    new_node->data=input; 
    new_node -> next = top;  
    top = new_node; 
} 

void pop(){ 
    if(top == NULL){ 
        printf("Stack Underflow!\n"); 
        return; 
    } else { 
        struct node *temp = top; 
        top = top -> next; 
        free(temp); 
    } 
} 

void show(){ 
    struct node *temp; 
    temp = top; 

    while(temp){ 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    }  
    printf("NULL\n"); 
} 

int main(){ 
    int choice, input; 

    while(1){ 
        printf("\nPerform operations on the stack:"); 
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End"); 
        printf("\n\nEnter the choice: "); 
        scanf("%d", &choice); 

        switch (choice){ 
        case 1: 
            printf("Insert Number: "); 
            scanf("%d",&input); 
            push(input); 
            break; 
        case 2: 
            pop(); 
            break; 
        case 3:  
            show(); 
            break; 
        case 4: 
            printf("Program terminated\n"); 
            return 0; 
        default: 
            printf("Invalid Choice!\n"); 
            break; 
        } 
    } 
    return 0; 
} 
