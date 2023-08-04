//  Name: Jordan Tong
//  Date: 4/13/23
//  Approach: I created a student structure with name, marks, total, and grade elements. Then I calculated the 
//  percentage score from the total marks so that I could easily assign a letter grade based on the students marks.
//  Challenges: It was not giving the intended output for total because was not iterating correctly. To fix this I
//  created a variable n to be the size of the array which made it look more neat and able to iterate over the 
//  entire array. It was also giving me a warning because it told be I was assigning a char pointer to a char 
//  variable when I enclosed the letters in double quotes. To fix this I used single quotes instead.

#include <stdio.h>

int main() {
    struct student {    // Student structure with 4 elements name, marks, total, and grade.
        char name[50];
        int marks[4];
        int total;
        char grade;
    }s;
    int nmarks = sizeof(s.marks) / sizeof(s.marks[0]);
    printf("Name: ");
    scanf("%s", &s.name);
    for (int i = 0; i < 5; i++) {
        int j = i + 1;
        printf("Enter the marks for subject %d (out of 100): ", j);
        scanf("%d", &s.marks[i]);
    }
    for (int i = 0; i < nmarks; i++) {
        s.total += s.marks[i];
    }
    int percentage = (((double)s.total) / 500) * 100;   // Percentage grade calculation
    if (percentage >= 90) { // Assigning letter grade.
        s.grade = 'A';
    } else if (percentage >= 80) {
        s.grade = 'B';
    } else if (percentage >= 70) {
        s.grade = 'C';
    } else if (percentage >= 60) {
        s.grade = 'D';
    } else {
        s.grade = 'F';
    }
    printf("\nHello %s, your total marks are %d and grade %c", s.name, s.total, s.grade);
    return 0;
}