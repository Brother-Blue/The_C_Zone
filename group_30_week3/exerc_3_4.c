/* ====================================
 File name: exerc_3_4.c
 Date: 2021-02-04
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Demonstration code: []
 ====================================== */

#include <stdio.h>
#include <stdlib.h>

// Menu options
const char menu[] = "\n 1. Create new file (deletes old file) \
                    2. Add new person to file \
                    \n 3. Search for person in file \
                    \n 4. Print file \
                    \n 5. Exit\n\n";

typedef struct PERSON {
    char firstName[20];
    char lastName[20];
    char personnummer[13]; // yyyymmddxxxx
} PERSON;

char fileName[] = "record.bin"; // Fixed file name

// Method declarations
void clear_stdin();
void handleInput(int input);

PERSON input_record(void); // Reads in a person record
void write_new_file(char *fileName); // Create file record and write demo user to it
void append_to_file(PERSON *person); // Append a new user to the end of the record
void print_file(void); // Print out the entire file
void search_by_name(char *name); // Print out the person if they exist in the list

// Main
int main(void)
{
    printf("Please select a menu option: \n");
    printf(menu);
    int choice;
    while (1)
    {
        printf("\n>> ");
        scanf("%d", &choice);
        handleInput(choice);
    }
    return 0;
}

// Courtesy of exerc_2_8
void clear_stdin()
{
    while (getchar() != '\n')
    {
        ;
    }
}

// Create a new file and init it with a sample name
void write_new_file(char *fileName) {
    struct PERSON user = {
        .firstName = "John",
        .lastName = "Doe",
        .personnummer = "191209142172"
    };
    FILE *p_file; // Init a new pointer
    // Remove existing file
    remove(fileName); 
    // Open the file in write-binary mode
    p_file = fopen(fileName, "wb"); 
    // Write the data to the file, sizeof(user)-1 is to remove the \0
    fwrite(&user, sizeof(struct PERSON)-1, 1, p_file); 
    // New line after entry
    fwrite("\n", 1, 1, p_file);
    // Close the file
    fclose(p_file);
    printf("New file created.\n");
}

// Add a new entry to the record
void append_to_file(PERSON *person) {
    FILE *p_file; // Init a new pointer
    // Open the file in append mode
    p_file = fopen(fileName, "ab");
    // Write the data to the file, sizeof(user)-1 is to remove the \0
    fwrite(person, sizeof(struct PERSON)-1, 1, p_file);
    // New line after entry
    fwrite("\n", 1, 1, p_file);
    // Close the file
    fclose(p_file);
    printf("Entry added to the record.");
}

// Search record for a person with matching first or last name
void search_by_name(char *name) {
    FILE *p_file; // Init new pointer
    int count = 1, fComp, lComp;
    struct PERSON p; // Init an empty PERSON to assign the record values to
    p_file = fopen(fileName, "rb"); // Assign the pointer
    // While there is a record print it out and increment the entry count
    while (fread(&p, sizeof(struct PERSON), 1, p_file)) {
        fComp = strcmp(p.firstName, name); // Check if the first name matches the search
        lComp = strcmp(p.lastName, name); // Check if the last name matches the search
        // If the names match then print the value
        if (fComp == 0 || lComp == 0) {
            printf("Entry %d: %s %s, SSN: %s\n", count++, p.firstName, p.lastName, p.personnummer);
        }
    }
    // Close the file
    fclose(p_file);
    free(name);
}

// Print out the entire file
void print_file(void) {
    FILE *p_file; // Init new pointer
    int count = 1; // Start entry count at 1
    struct PERSON p; // Init an empty PERSON to assign the record values to
    p_file = fopen(fileName, "rb"); // Assign the pointer
    // While there is a record print it out and increment the entry count
    while (fread(&p, sizeof(struct PERSON), 1, p_file)) {
        printf("Entry %d: %s %s, SSN: %s\n", count++, p.firstName, p.lastName, p.personnummer);
    }
    // Close the file
    fclose(p_file);
}

// Create a new person
PERSON input_record(void) {
    // Create a default record
    PERSON person = {
        .firstName = "John",
        .lastName = "Doe",
        .personnummer = "199912246167"
    };
    // Prompt user for first name
    printf("Please enter the person's first name: \n>> ");
    // Assign the first name to the person->firstName
    scanf("%s", person.firstName);
    clear_stdin();
    // Prompt user for last name
    printf("Please enter the person's last name: \n>> ");
    // Assign the last name to the person->lastName
    scanf("%s", person.lastName);
    clear_stdin();
    // Prompt user for a personnummer
    printf("Please enter the person's personal number (yyyymmddxxxx): \n>> ");
    // Assign the personnummer to the person->personnummer
    scanf("%s", person.personnummer);
    clear_stdin();
    // Return the person
    return person;
}

// Handles user input
void handleInput(int input)
{
    switch (input)
    {
    case 1:
        // Create a new record
        write_new_file(fileName);
        break;
    case 2:
        printf(""); // Needed this because the case was seen as a label and assigning a value after declaring a label threw errors
        PERSON person = input_record(); // Get a new person
        // Pass the new person to append file
        append_to_file(&person);
        break;
    case 3:
        // Search for a person with matching first or last name
        printf("Please enter the first or last name of the person you are searching for: \n>> ");
        char name[] = "";
        scanf("%s", &name);
        search_by_name(name);
        break;
    case 4:
        // Print the entire file
        print_file();
        break;
    case 5:
        // Exit the program
        printf("Goodbye.\n");
        exit(0);
        break;
    default:
        printf("Invalid input\n");
        break;
    }
}