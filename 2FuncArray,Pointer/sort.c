#include <stdio.h>

int main() {
    int input[10];
    int n = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < 10; i++) {
        scanf("%d", &input[i]);
    }
    // Iterates through the array comparing two elements of the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (input[j] > input[j + 1]) {  // Swap algorithm
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("\n%d", input[i]);
    }
    return 0;
}