// Name: Jordan Tong
// Date Created: 4/4/23
// Approach: Used the brute force method of iterating through an array and used pointers to find the minimum 
// and maximum value.
// Challenges: Whenever I was executing the program the minimum was giving me the unintended output. Initially
// I set min and max to the first and last elements of the array which was not iterating correctly. To fix this, I
// initialized the min and max to the address of the first element of the array.
#include <stdio.h>

int main() {
    int size, *min, *max;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int array[size];
    int n = sizeof(array) / sizeof(array[0]);
    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    min = &array[0];
    max = &array[0];
    // Starting from the last integer in the array and comparing each integer and if it finds one that is 
    // greater it is updated
    for (int i = 0; i < n; i++) {
        if (*(array + i) > *max) {
            *max = *(array + i);
        }
    }
    printf("\nMaximum: %d", *max);
    // Starting from the first integer in the array and comparing each integer and if it finds one that is
    // smaller it is updated
    for (int i = 0; i < n; i++) {
        if (*(array + i) < *min) {
            *min = *(array + i);
        }
    }
    printf("\nMinimum: %d", *min);
    return 0;
}