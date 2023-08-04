//  Name: Jordan Tong
//  Date: 4/4/23
//  Approach: I prompted the user to enter the size and the elements of the array. Then I iterated through
//  the array in reverse order of addresses in the array and printed them out
//  Challenges: At firt it was ouputting a garbage value followed by the reverse array. I found that it was 
//  not iterating correctly because it was starting at the size of the array but I needed to start at size - 1

#include <stdio.h>

int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int array[size];
    int n = sizeof(array) / sizeof(array[0]);
    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < n; i ++) {
        scanf("%d", &array[i]);
    }
    printf("Reversed array: ");
    // Traverses and prints the array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", *(array + i));
    }
    return 0;
}
