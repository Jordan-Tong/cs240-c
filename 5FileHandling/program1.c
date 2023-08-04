//  Name:Jordan Tong
//  Date:4/25/23
//  Approach: Created an account structure to better organize each persons account id, name, and balance. Then used
//  the fgets function to read each line of the csv file which stops reading once encountering the EOF character
//  and exitting the while loop. Then I split the string by tokens using the "," as the delimitter. Then I sorted
//  the array structure in order to find the top 5 accounts based on highest balance.
//  Challenges: One challenge I faced was how to read all the lines of the csv file. Then I realized after research
//  that every call of the fgets function reads a new line from a file. Another challenge I faced was separated the 
//  each line in the csv file into different tokens. After playing around and doing some research I found out you 
//  can separate strings with multiple strtok calls. After playing around with the fgets function I noticed that 
//  each call of fgets on the input returns the next line.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct account {
        int id;
        char name[100];
        double balance;
    }account;

int main() {
    FILE *input;
    input = fopen("accounts.csv", "r");
    struct account accounts[1000];
    const char delim[2] = ",";
    int totalacc = 0;
    char string[1024];
    double totalbal = 0;
    fgets(string, sizeof(string), input);   //Skips the header line
    
    while (fgets(string, sizeof(string), input)) {  // Splits string into tokens
        char *token;
        token = strtok(string, delim);
        accounts[totalacc].id = atoi(token);    // Converts string token to integer
        token = strtok(NULL, delim);
        strncpy(accounts[totalacc].name, token, sizeof(accounts[totalacc].name));
        token = strtok(NULL, delim);
        token++;    // Skips the $
        accounts[totalacc].balance = atof(token);   // Converts string token to float
        totalacc++;
    }
    fclose(input);
    
    for (int i = 0; i < totalacc; i++) {    // Increments total balance with each balance in every account
        totalbal += accounts[i].balance;
    }
    for (int i = 0; i < totalacc; ++i){ // Sorts by account with highest balance
        for (int j = i + 1; j < totalacc; ++j){
            if (accounts[i].balance < accounts[j].balance){
                struct account temp = accounts[i];
                accounts[i] = accounts[j];
                accounts[j] = temp;
            }
        }
    }
    printf("Total Accounts: %d\n", totalacc);
    printf("Total balance: $%.2lf", totalbal);

    printf("\nTop 5 accounts: \n");
    for (int i = 0; i < 5; i ++) {
        printf("%d %s: $%.2lf\n",accounts[i].id, accounts[i].name, accounts[i].balance);
    }
    return 0;
}