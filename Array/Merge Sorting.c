#include <stdio.h>

// Function to merge two subarrays
void merge(int array[], int l, int m, int r) {
    int left_length = m - l + 1;
    int right_length = r - m;
    
    int temp_left[left_length];
    int temp_right[right_length];
    
    int i, j, k;
    
    // Copy data to temporary arrays temp_left[] and temp_right[]
    for (i = 0; i < left_length; i++) {
        temp_left[i] = array[l + i];
    }
    
    for (i = 0; i < right_length; i++) {
        temp_right[i] = array[m + 1 + i];
    }
    
    // Merge the temporary arrays back into array[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    
    while (i < left_length && j < right_length) {
        if (temp_left[i] <= temp_right[j]) {
            array[k] = temp_left[i];
            i++;
        } else {
            array[k] = temp_right[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of temp_left[], if there are any
    while (i < left_length) {
        array[k] = temp_left[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of temp_right[], if there are any
    while (j < right_length) {
        array[k] = temp_right[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void divide(int a[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Recursively sort first and second halves
        divide(a, left, mid);
        divide(a, mid + 1, right);
        
        // Merge the sorted halves
        merge(a, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the merge sort
int main() {
    int arr[] = {15, 20, 7, 3, 81, 22};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Given array is \n");
    printArray(arr, arr_size);
    
    divide(arr, 0, arr_size - 1);
    
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    
    return 0;
}
