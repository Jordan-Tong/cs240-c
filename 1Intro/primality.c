#include <stdio.h>

int main() {
    int input;
    printf("Enter input: ");
    scanf("%d", &input);
    int i = 0;
    int temp = 0;
    // If the input is 1 automatically exit as 1 is not a prime number.
    if (input == 1) {
        printf("Not prime");
        return 0;
    }
    // If the input is divisable by any number it is not prime.
    for (i = 2; i * i <= input; i++) {
        if (input % i == 0) {
            temp++;
        }
    }
    if (temp == 0) {
        printf("Prime");
    } else{
        printf("Not prime");
    }

    return 0;
}