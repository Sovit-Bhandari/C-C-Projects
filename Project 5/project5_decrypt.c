/*
Name = Sovit Bhandari
Discription = The following code prompts the user to input a message, then employs a decoding algorithm to reveal the hidden text. It consists of functions to take user input, decode the message, and display the revealed content.
*/

#include <stdio.h>

#define MAXIMUM_LENGTH 1000

void decrypt(char *input, char *output);                            // Function prototype for decoding

int main() {
    char coded_text[MAXIMUM_LENGTH + 1];                            // Array to store the coded text
    char decoded_text[MAXIMUM_LENGTH + 1];                          // Array to store the decoded text

    printf("Enter message: ");
    fgets(coded_text, MAXIMUM_LENGTH, stdin);                       // Use fgets for safer input handling

    decrypt(coded_text, decoded_text);                              // Calling function to decode the input

    printf("Output: %s", decoded_text);                           // Print the decoded text
    return 0;
}

// Function to decode the input text
void decrypt(char *input, char *output) {
    char *source = input;                                           // Pointer to the source (input) text
    char *target = output;                                          // Pointer to the target (output) text
    int step = 1;
    while (*source != '\0') {
        *target = *source;
        source += step;                                             // Move the source pointer by 'step'
        step++;
        target++;
    }
    *target = '\0';                                                 // Add null terminator to mark the end of the decoded string
}
