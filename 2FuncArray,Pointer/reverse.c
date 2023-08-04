#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int array[size];    // Declares an array initialized with the given size
    printf("\nElements of the array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    // Iterates through the array in reverse order
    for (int i = size - 1; i >= 0; i--) {
        printf("\n%d", array[i]);
    }
    return 0;
}