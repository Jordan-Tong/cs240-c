#include <stdio.h>

int main() {
    printf("Enter expression:");
    char operation;
    int first;
    int second;
    scanf("%d %c %d", &first, &operation, &second);
    // Switch case to compare operator from user input to desired operation.
    switch (operation) {
        case '+':
            printf("%d", first + second);
            break;
        case '-':
            printf("%d", first - second);
            break;
        case '*':
            printf("%d", first * second);
            break;
        case '/':
            printf("%d", first / second);
            break;
        case '%':
            printf("%d", first % second);
            break;               
    }
    return 0;
}