//  Name: Jordan Tong
//  Date: 4/26/23
//  Approach: For the import function I recycled the string splitting method that I used from program1 of the 
//  homework where I was able to split the lines in the csv file and able to copy it over to the bin file.
//  Challenges: I was stuck on how to remove a specific line from a file. But I learned that you can just create a
//  temporary file where you can copy all lines except the line to be deleted renaming it to the original file and
//  removing the old file and the result is the file with the line deleted. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_SIZE 1024
#define MAX_LINE_SIZE 100

struct phonebook
{
    char name[20];
    char number[10];
};

FILE *phonebook_file()
{
    FILE *fptr;
    if ((fptr = fopen("phonebook.bin", "ab+")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    return fptr;
}

FILE *phonebook_file1() {
    FILE *fptrcsv;
    if ((fptrcsv = fopen("phonebook.csv", "r+")) == NULL) {
        printf("Error ! opening csv file");
        exit(1);
    }
    return fptrcsv;
}

void add_contact(FILE *fptr)
{
    struct phonebook contact;
    printf("Enter name: ");
    scanf("%s", contact.name);
    printf("Enter number: ");
    scanf("%s", contact.number);
    fwrite(&contact, sizeof(struct phonebook), 1, fptr);
    printf("Contact added successfully\n");
}

void search_contact(FILE *fptr)
{
    struct phonebook contact;
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    rewind(fptr);
    while (fread(&contact, sizeof(struct phonebook), 1, fptr) == 1)
    {
        if (strcmp(contact.name, name) == 0)
        {
            printf("Number: %s\n", contact.number);
            return;
        }
    }
    printf("Contact not found.\n");
}

void display_all_contacts(FILE *fptr)
{
    struct phonebook contact;
    rewind(fptr);
    printf("Lisiting contacts:\n");
    while (fread(&contact, sizeof(struct phonebook), 1, fptr) == 1)
    {
        printf("Name: %s\tNumber: %s\n", contact.name, contact.number);
    }
}

// Creates a new temp file and copies all lines except the line to be deleted renaming it to the bin file. 
void delete_contact(FILE *fptr) {
    struct phonebook contact;
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);
    FILE *temp;
    temp = fopen("temp_file.bin", "ab+");
    rewind(fptr);
    while (fread(&contact, sizeof(struct phonebook), 1, fptr) == 1) {
        if (strcmp(contact.name, name) != 0) {
            fwrite(&contact, sizeof(struct phonebook), 1, temp);
        }
    }
    remove("phonebook.bin");
    rename("temp.bin", "phonebook,bin");
    printf("Contact successfully deleted.");
}

// Splits string by tokens and copies from the csv file to bin file
void import(FILE *fptr, FILE *fptrcsv) {
    struct phonebook contact;
    char string[1024];
    const char delim[2] = ", ";
    fgets(string, sizeof(string), fptrcsv);
    while (fgets(string, sizeof(string), fptrcsv)) {
        char *token;
        token = strtok(string, delim);
        strcpy(contact.name, token);
        token = strtok(NULL, delim);
        strcpy(contact.number, token);
        fwrite(&contact, sizeof(struct phonebook), 1, fptr);
    }
    fclose(fptrcsv);
    printf("Imports successful.\n");
}

//  Exports contact name and number with specified format.
void export(FILE *fptr, FILE *fptrcsv) {
    struct phonebook contact;
    rewind(fptr);
    while (fread(&contact, sizeof(struct phonebook), 1, fptr) == 1)
    {
        fprintf(fptrcsv, "%s,%s\n", contact.name, contact.number);
    }
    fclose(fptrcsv);
    printf("Exports successful.\n");
}

int main()
{
    // open the phonebook file
    FILE *fptr = phonebook_file();
    FILE *fptrcsv = phonebook_file1();

    while (1)
    {
        int choice;
        printf("---------MENU---------\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Import from CSV\n");
        printf("6. Export to CSV\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("----------------------\n");
        switch (choice)
        {
        case 1:
            add_contact(fptr);
            break;
        case 2:
            delete_contact(fptr);
            break;    
        case 3:
            search_contact(fptr);
            break;
        case 4:
            display_all_contacts(fptr);
            break;
        case 5:
            import(fptr, fptrcsv);
            break;
        case 6:
            export(fptr, fptrcsv);
            break;       
        case 7:
            fclose(fptr);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}