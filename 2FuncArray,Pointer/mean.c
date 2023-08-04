#include <stdio.h>

int main() {
    int size;
    int sum = 0;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int elements[size];
    int n = sizeof(elements) / sizeof(elements[0]);
    printf("\nElements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }
    for (int i = 0; i < n; i++) {
        sum += elements[i];
    }
    double mean = (double)sum / size;
    printf("\n%.2lf", mean);
    return 0;
}