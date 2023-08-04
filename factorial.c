#include <stdio.h>

int main() {
    printf("Enter an Integer: ");
    int userinput;
    scanf("%d", &userinput);
    int output = userinput;
    int num = 1;
    // Factorial formula
    for (num = userinput - 1; num > 0; num--) {
        output *= num;
    }
    printf("%d", output);

    return 0;
    }