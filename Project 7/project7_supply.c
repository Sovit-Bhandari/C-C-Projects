/*
Name = Sovit Bhandari
U-Id= U83561265
Discription = The C program reads supply data from a CSV file, prompts the user to search for a supply by name, and then writes matching 
supply information to another CSV file. It employs file handling, string manipulation, and structure usage to achieve this. Upon completion,
 it notifies the user of the successful writing of search results to the output file.
*/

#include <stdio.h>                                                              // Include standard input-output library
#include <stdlib.h>                                                             // Include standard library
#include <string.h>                                                             // Include string manipulation functions

#define MAX_SUPPLIES 200                                                        // Define maximum number of supplies
#define MAX_NAME_LENGTH 100                                                     // Define maximum length of supply name
#define MAX_COLOR_LENGTH 100                                                    // Define maximum length of supply color

struct supply {                                                                 // Define a structure to represent a supply
    char name[MAX_NAME_LENGTH];                                                 // Name of the supply
    char color[MAX_COLOR_LENGTH];                                               // Color of the supply
    int quantity;                                                               // Quantity of the supply
};

int read_line(char *str, int n, FILE *fp) {                                     // Function to read a line from a file
    int ch, i = 0;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {                             // Loop until newline or end of file
        if (i < n - 1)                                                          // Check if there's space in the buffer
            str[i++] = ch;                                                      // Store character in buffer
    }
    str[i] = '\0';                                                              // Null terminate the string

    return i;                                                                   // Return the number of characters read
}

int search(struct supply list[], int n, struct supply result[], char *search_name) { // Function to search for supplies
    int count = 0;                                                              // Initialize count of matching supplies

    for (int i = 0; i < n; ++i) {                                               // Loop through the list of supplies
        if (strcmp(list[i].name, search_name) == 0) {                           // Check if name matches search term
            strcpy(result[count].name, list[i].name);                           // Copy name to result array
            strcpy(result[count].color, list[i].color);                         // Copy color to result array
            result[count].quantity = list[i].quantity;                          // Copy quantity to result array
            ++count;                                                            // Increment count of matching supplies
        }
    }

    return count;                                                               // Return the number of matching supplies found
}

int main() {                                                                    // Main function
    FILE *input_file = fopen("supply.csv", "r");                                // Open input file in read mode
    FILE *output_file = fopen("result.csv", "w");                               // Open output file in write mode

    if (input_file == NULL || output_file == NULL) {                            // Check if files opened successfully
        printf("Error opening files.\n");                                       // Print error message
        return 1;                                                               // Exit with error code
    }

    struct supply supplies[MAX_SUPPLIES];                                       // Array to store supplies
    int num_supplies = 0;                                                       // Initialize count of supplies

    // Read supplies from file
    while (fscanf(input_file, "%[^,], %[^,], %d\n", supplies[num_supplies].name,
                  supplies[num_supplies].color, &supplies[num_supplies].quantity) == 3) {
        num_supplies++;                                                         // Increment count of supplies
    }

    fclose(input_file);                                                         // Close input file

    printf("Enter supply: ");                                                   // Prompt user for input
    char search_name[MAX_NAME_LENGTH];                                          // Buffer to store search term
    read_line(search_name, MAX_NAME_LENGTH, stdin);                             // Read user input

    struct supply search_results[MAX_SUPPLIES];                                 // Array to store search results
    int num_results = search(supplies, num_supplies, search_results, search_name); // Perform search

    // Write matching supplies to output file
    for (int i = 0; i < num_results; ++i) {                                     // Loop through search results
        fprintf(output_file, "%s, %s, %d\n", search_results[i].name, search_results[i].color, search_results[i].quantity); // Write to output file
    }

    fclose(output_file);                                                        // Close output file

    printf("Search results written to result.csv.\n");                          // Notify user

    return 0;                                                                   // Exit successfully
}
