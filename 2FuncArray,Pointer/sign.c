#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);
    if (input < 0) {
        printf("%d is a negative number", input);
    } else {
        printf("%d is a positive number", input);
    }
    return 0;
}