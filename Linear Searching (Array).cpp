#include <stdio.h> 
#define MAXSIZE 20 

int main(){ 
    // Request input size
    int num[MAXSIZE], count, i, x, a; 
    printf("How many number >> "); 
    scanf("%d", &count); 

    // If input size > MAXSIZE, display error message
    if (count > MAXSIZE){ 
        printf("Array Overflow!"); 
        return 0; 
    } 

    // Request new data
    while (i < count){ 
        printf("Enter number #%d >> ", i+1); 
        scanf("%d", &num[i]); 
        i++; 
    }

    // Display submitted data
    printf("\nData submitted  >> "); 
    while (x < count){ 
        printf("| %d ", num[x]); 
        x++; 
    }

    int search, sign; 
    // Request data to search
    printf("\nSearch >> "); 
    scanf("%d", &search); 
    // Traverse array and compare with the input
    for (a = 0; a < count; a++){ 
        // If found, display it and set sign = 1
        if (num[a] == search){ 
            printf("\nData %d is found on %dth position!", search, a+1); 
            sign = 1; 
        } 
    }
    // If sign = 0, display error message
    if (sign != 1){ 
        printf("\nData not found!"); 
    } 
    return 0; 
} 
