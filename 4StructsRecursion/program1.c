//  Name: Jordan Tong
//  Date: 4/11/23
//  Approach: First I created a structure named Physician which contains the name and specialization. Then I 
//  created 
//  Challenges: When I tried using the string compare function it was not giving me any output because there was no
//  condition being given. To fix this i compared it with 0 because if the two strings are equal the function 
//  returns 0.

#include <stdio.h>
#include <string.h>

int main(){
    int size, querynum, count;
    char input[50];
    printf("Enter the number of doctors: ");
    scanf("%d", &size);
    // Declaring a physician structure with name and specialization as elements.
    struct physician {
        char name[50];
        char specialization[50];
    };
    struct physician p[size];   // Declaring a physician array of size given as input.
    int n = sizeof(p) / sizeof (p[0]);
    printf("Enter the name and specialization of the doctors: \n");
    for (int i = 0; i < n; i++) {
        scanf("%s %s", &p[i].name, &p[i].specialization);
    }

    printf("\nEnter the number of queries: ");
    scanf("%d", &querynum);
    for (int i = 1; i <= querynum; i++) {
        if (i > 1) {
            printf("\n");
        }
        printf("\nEnter the query(%d): ", i);
        scanf("%s", &input);
        printf("Result(%d): ", i);
        for (int j = 0; j < n; j++) {
            if (strcmp(input, p[j].specialization) == 0) {
                printf("%s ", p[j].name);
                count++;
            } else if (j == (n - 1) && count == 0) {
                printf("None");
            }
        }
    }
    return 0;
}