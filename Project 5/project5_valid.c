/*
    Name: Sovit Bhandari
    Description: This program checks if the command-line arguments contain only allowed characters. It verifies if the number of arguments is greater than 2 (including the program name). Allowed characters include lowercase alphabets, digits, spaces, exclamation marks, question marks, and periods.
*/

#include <stdio.h>    // Include standard input-output library
#include <ctype.h>    // Include character handling library

// Function to check if the input string contains allowed characters
int is_valid_data(const char *data) {
    while (*data) {    // Iterate through the characters of the string until the null terminator is encountered
        if (!islower(*data) && !isdigit(*data) && *data != ' ' &&    // Check if the character is not lowercase alphabet, digit, or space
            *data != '!' && *data != '?' && *data != '.') {
            return 0;    // Return 0 if an invalid character is found
        }
        data++;    // Move to the next character in the string
    }
    return 1;    // Return 1 if all characters are valid
}

int main(int num_args, char *arguments[]) {
    if (num_args <= 2) {    // Check if the number of arguments is less than or equal to 2
        printf("invalid number of arguments\n");    // Print error message for insufficient arguments
        return 1;    // Return error status
    }

    // Assuming the first element (arguments[0]) is the program name
    for (int index = 1; index < num_args; index++) {    // Iterate through the command-line arguments
        if (!is_valid_data(arguments[index])) {    // Check if the argument contains allowed characters
            printf("invalid\n");    // Print "invalid" if any argument contains invalid characters
            return 0;    // Exit the program with success status
        }
    }

    printf("valid\n");    // If all arguments are valid, print "valid"
    return 0;    // Return success status
}
