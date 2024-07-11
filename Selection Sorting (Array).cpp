#include <stdio.h> 
#define MAXSIZE 100 

int data[MAXSIZE], n, x; 

int main() { 
    printf("How many number to sort? : "); 
    scanf("%d", &n); 
    for (x=0; x < n; x++){ 
        printf("Enter #%d integer: ", x+1); 
        scanf("%d", &data[x]); 
    } printf("\n"); 

    // Run through the array 9 times 
    for (int num = 0; num < n - 1; num++) { 
        int small = num; // Set the initial small value 
        // Compare initial small value with the next element in array 
        for (int scan = num + 1; scan < n; scan++) { 
            if (data[scan] < data[small]) { 
                // Found smaller value? Then set it as new small value 
                small = scan; 
            } 
        } 

        // Swap with new small value 
        int temp = data[small]; 
        data[small] = data[num]; 
        data[num] = temp; 

        // Print array position in this loop a.k.a step 
        printf("Step %2d: ", num+1); 
        for (int i = 0; i < n; i++) { 
            printf("%d ", data[i]); 
        } 
        printf("\n"); 
    } 
    return 0; 
} 
