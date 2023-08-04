#include <stdio.h>

int main() {
    char name[20];
    printf("Name: ");
    scanf("%20s", &name);
    const int year;
    const int month;
    const int day;
    // Calculate difference in days and convert into months and year. i.e 365 days in year 30 days month.
    printf("Date of Birth: ");
    scanf("%4d%*c%02d%*c%02d", &year, &month, &day);
    printf("Year: %d, Month: %d, Days: %d", year, month, day);
    
    int currentYear = 2023;
    int currentMonth = 02;
    int currentDays = 15;
    if (year == currentYear) {
        int toDays = ((30 - day) + (currentMonth - month + 1) + currentDays);
        int ageMonth = toDays / 30;
        int ageDay = (toDays - (ageMonth * 30));
        printf("\nHello, %s! You are 0 years, %d months, and %d days old.", name, ageMonth, ageDay);
    } else {
    int roundDate = 365 - day - ((month - 1) * 30); // Rounds date up to the next year to easily convert days left in the year.
    int converttoDays = ((currentYear - (year + 1)) * 365) + roundDate + (currentMonth * 30);    // Converts difference between dates in days.
    printf("\n%d", converttoDays);
    // Converts the total days to years, months, and days.
    int ageYears = converttoDays / 365;
    int ageMonths = (converttoDays - (ageYears * 365)) / 30;
    int ageDays = converttoDays - (ageYears * 365) - (ageMonths * 30);
    printf("\nHello, %s! You are %d years, %d months, and %d days old.", name, ageYears, ageMonths, ageDays);
    }
    return 0;
}