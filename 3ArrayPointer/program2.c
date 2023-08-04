// Name: Jordan Tong
// Date: 4/4/23
// Approach: I prompted the user to enter the two string which I assigned to pointer variables which I then
// used the string concatenation function to concatenate the two strings.
// Challenges: I was trying to use the assign the strcat of two strings to a char variable but it was giving
// me an error because I was casting a char pointer to a character so instead I directly printed the 
// concatenation of the two strings.
#include <stdio.h>
#include <string.h>

int main() {
    char *str1, *str2;
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("\nEnter the second string: ");
    scanf("%s", str2);
    printf(strcat(str1, str2));
    return 0;
}