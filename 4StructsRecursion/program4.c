//  Name: Jordan Tong
//  Date: 4/16/23
//  Approach: Iterates through the string and subtracts 32 to find the uppercase of that letter. 
//  Challenges: It wasn't assigning the entire string to the str array. To fix this I used the gets function which
//  takes the entire line into a string. When I subtracted the 32 it got rid of the space instead I added a 
//  an if statement that only updates the character if it is a lowercase character between a and z.

#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    printf("Enter string: ");
    gets(str);
    int n = strlen(str);
    char strings[50];
    
    printf("Output string: ");
    for (int i = 0; i < n; i++) {
        if ('a' <= str[i] && 'z' >= str[i]) {
            str[i] = str[i] - 32;   // If the character is from a to z then updates it to the uppercase
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }
    return 0;
}