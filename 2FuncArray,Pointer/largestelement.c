#include <stdio.h>

int main() {
    int input[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &input[i]);
    }
    int largest = input[0];
    for (int t = 1; t < 10; t++) {
        if (input[t] > largest) {
            largest = input[t];
        }
    }
    printf("\n%d", largest);
    return 0;
}