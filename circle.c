#include <stdio.h>

float main() {
    const float pi = 3.14159;
    int radius;
    printf("Enter radius: ");
    scanf("%d", &radius);
    float area = pi * (radius * radius);
    float circumference = 2 * pi * radius;
    printf("\nArea = %0.4f", area);
    printf("\nCircumference = %0.4f", circumference);
    return 0;
}