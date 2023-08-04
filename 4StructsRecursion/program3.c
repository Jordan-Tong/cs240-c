//  Name: Jordan Tong
//  Date: 4/16/23
//  Approach: Instead of iterating through the array using a for loop I used the pointers to iterate through the 
// addresses of the array which made it a lot simpler. 
//  Challenges: At first I tried iterating through the string and swapping character but it ended up being too 
// too confusing so I decided to iterate through the string using pointers. It was also not assigning the entire
// string so instead of using the scanf function I used the gets function to assign the entire line to the word 
// variable.

#include <stdio.h>

void reverse(char *word) {
   if (*word != '\0') { // Iterates through the string recursively until it reachs a null character.
      reverse(word + 1);
      printf("%c", *word);
   }
}

int main() {
   char word[50];
   printf("Enter word: ");
   gets(word);
   printf("Reverse Output: ");
   reverse(word);
   return 0;
}