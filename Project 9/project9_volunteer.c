/*
Name = Sovit Bhandari
U-Id= U83561265
Discription = Following program manages a volunteer database through console input. It defines a struct for volunteer information and implements functions 
for adding, searching, printing, and deleting volunteers. Each volunteer has a last name, first name, email, and grade level. The main function offers 
options to add, search, print, delete, or quit. Volunteers are stored in a linked list. Input validation and memory management are incorporated. The program
efficiently handles volunteer data while providing a user-friendly interface for database management.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMAIL_LEN 100
#define NAME_LEN 30

// Structure definition for storing volunteer information
struct volunteer {
    char first[NAME_LEN + 1];                                                                                       // Store first name
    char last[NAME_LEN + 1];                                                                                        // Store last name
    char email[EMAIL_LEN + 1];                                                                                      // Store email address
    int grade_level;                                                                                                // Store grade level
    struct volunteer *next;                                                                                         // Pointer to the next volunteer
};

// Function prototypes
struct volunteer *add_to_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
int read_line(char str[], int n);
struct volunteer *delete_from_list(struct volunteer *list);

// Main function
int main(void) {
    char code;
    struct volunteer *volunteer_list = NULL;
    printf("Operation Code: a for adding to the list, s for searching, d for deleting from the list, p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');                                                                                 // skips to end of line
        switch (code) {
            case 'a':
                volunteer_list = add_to_list(volunteer_list);
                break;
            case 's':
                search_list(volunteer_list);
                break;
            case 'p':
                print_list(volunteer_list);
                break;
            case 'd':
                volunteer_list = delete_from_list(volunteer_list);
                break;
            case 'q':
                clear_list(volunteer_list);
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

// Function to add a new volunteer to the list
struct volunteer *add_to_list(struct volunteer *list) {
    struct volunteer *new_volunteer = malloc(sizeof(struct volunteer));                                           // Allocate memory for new volunteer
    if (new_volunteer == NULL) {                                                                                  // Check if memory allocation failed
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter last name: ");
    read_line(new_volunteer->last, NAME_LEN);                                                                    // Read last name from input
                                                            
    printf("Enter first name: ");                                                                                                                                   
    read_line(new_volunteer->first, NAME_LEN);                                                                   // Read first name from input
                                                            
    printf("Enter email address: ");                                                                                                                                    
    read_line(new_volunteer->email, EMAIL_LEN);                                                                  // Read email address from input
                                                        
    printf("Enter grade level: ");                                                               
    scanf("%d", &new_volunteer->grade_level);                                                                    // Read grade level from input
    while (getchar() != '\n');                                                                                   // Clear input buffer
                                                        
    new_volunteer->next = NULL;                                                                                  // Set next pointer to NULL

    // Check if the volunteer already exists
    struct volunteer *current = list;
    while (current != NULL) {
        if (strcmp(current->email, new_volunteer->email) == 0 && strcmp(current->last, new_volunteer->last) == 0) {
            printf("Volunteer already exists.\n");
            free(new_volunteer);                                                                                // Free memory allocated for new volunteer
            return list;                                                                                        // Return the original list without adding the duplicate volunteer
        }
        current = current->next;                                                                                // Move to the next volunteer in the list
    }
    
    if (list == NULL) {                                                                                         // If the list is empty
        return new_volunteer;                                                                                   // Return the new volunteer as the start of the list
    } else {                                                                                                    // If the list is not empty
        struct volunteer *temp = list;
        while (temp->next != NULL) {
            temp = temp->next;                                                                                  // Traverse to the end of the list
        }
        temp->next = new_volunteer;                                                                             // Add the new volunteer to the end of the list
        return list;                                                                                            // Return the updated list
    }
}

// Function to search for volunteers by grade level
void search_list(struct volunteer *list) {
    int grade_level;
    printf("Enter grade level: ");
    scanf("%d", &grade_level);                                                                                  // Read grade level from input
    int found = 0;
    for (struct volunteer *cur = list; cur != NULL; cur = cur->next) {                                          // Iterate through the list
        if (cur->grade_level == grade_level) {                                                                  // If grade level matches
            printf("%-12s%-12s%-30s\n", cur->last, cur->first, cur->email);                                     // Print volunteer information
            found = 1;                                                                                          // Set found flag
        }
    }
    if (!found)                                                                                                 // If no volunteers found
        printf("Not found\n");                                                                                  // Print "not found"
}

// Function to print the list of volunteers
void print_list(struct volunteer *list) {
    struct volunteer *current = list;
    while (current != NULL) {                                                                                   // Iterate through the list
        // Print volunteer information with formatted width
        printf("%-12s%-12s%-30s%5d\n", current->last, current->first, current->email, current->grade_level);
        current = current->next;                                                                                // Move to the next volunteer in the list
    }
}

// Function to clear the entire list and free memory
void clear_list(struct volunteer *list) {
    struct volunteer *temp;
    while (list != NULL) {                                                                                      // Iterate through the list
        temp = list;                                                                                            // Store the current volunteer in a temporary variable
        list = list->next;                                                                                      // Move to the next volunteer in the list
        free(temp);                                                                                             // Free memory allocated for the current volunteer
    }
}

// Function to delete a volunteer from the list
struct volunteer *delete_from_list(struct volunteer *list) {
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    char email[EMAIL_LEN + 1];
    int grade_level;
    printf("Enter last name: ");
    read_line(last, NAME_LEN);
    printf("Enter first name: ");
    read_line(first, NAME_LEN);
    printf("Enter email address: ");
    read_line(email, EMAIL_LEN);
    printf("Enter grade level: ");
    scanf("%d", &grade_level);
    
    struct volunteer *prev = NULL;
    struct volunteer *current = list;

    // Traverse the list to find the volunteer to delete
    while (current != NULL) {
        if (strcmp(current->last, last) == 0 &&
            strcmp(current->first, first) == 0 &&
            strcmp(current->email, email) == 0 &&
            current->grade_level == grade_level) {
            if (prev == NULL) {                                                                                  // Deleting the first node
                list = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return list;
        }
        prev = current;
        current = current->next;
    }

    printf("Volunteer does not exist.\n");
    return list;
}

// Function to read a line from input with specified maximum length
int read_line(char str[], int n) {
    int ch, i = 0;
    while (isspace(ch = getchar()));                                                                            // Skip leading whitespace characters
    str[i++] = ch;                                                                                              // Store the first non-whitespace character
    while ((ch = getchar()) != '\n') {                                                                          // Read characters until newline
        if (i < n)                                                                                              // Check if within maximum length
            str[i++] = ch;                                                                                      // Store character in the string
    }                                                               
    str[i] = '\0';                                                                                              // Null-terminate the string
    return i;                                                                                                   // Return the length of the string
}
