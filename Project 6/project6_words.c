/*
Name = Sovit Bhandari
Discription = Following C program reads the text from the specified file, and checks whether any text is square. The first part of the text must match the second part of the text (for example, “noon” or “deed”). If any word is square, it will be written to the output file “output.txt”.

*/

#include <stdio.h> // Include standard input/output library for file operations
#include <string.h> // Include string manipulation functions

#define MAX_WORDS 1000 // Define maximum number of words
#define MAX_WORD_LENGTH 100 // Define maximum length of a word

int is_square(char *word); // Declare function prototype for checking if a word is a square

int main() {
    char input_file_name[101]; // Array to store input file name
    char word[MAX_WORD_LENGTH + 1]; // Array to store a single word from the file
    char words[MAX_WORDS][MAX_WORD_LENGTH + 1]; // Array to store multiple words from the file
    int word_count = 0; // Variable to count the number of words read

    // Prompt user to enter file name
    printf("Enter file name: ");
    scanf("%100s", input_file_name); // Read file name from user

    // Open input file
    FILE *input_file = fopen(input_file_name, "r"); // Open file in read mode
    if (input_file == NULL) { // Check if file opening is successful
        printf("Error opening input file.\n"); // Print error message
        return 1; // Return error code
    }

    // Read words from input file
    while (fscanf(input_file, "%s", word) == 1 && word_count < MAX_WORDS) { // Loop to read words until EOF or maximum word count
        strcpy(words[word_count], word); // Copy word to words array
        word_count++; // Increment word count
    }

    // Close input file
    fclose(input_file); 

    // Open output file
    FILE *output_file = fopen("output.txt", "w"); // Open file in write mode
    if (output_file == NULL) { // Check if file opening is successful
        printf("Error creating output file.\n"); // Print error message
        return 1; // Return error code
    }

    // Write words that are squares to output file
    for (int i = 0; i < word_count; i++) { // Loop through all words
        if (is_square(words[i])) // Check if word is a square
            fprintf(output_file, "%s\n", words[i]); // Write square word to output file
    }

    // Close output file
    fclose(output_file);

    printf("Output written to output.txt.\n"); // Print success message

    return 0; // Return success code
}

// Function to check if a word is a square
int is_square(char *word) {
    int len = strlen(word); // Get length of word
    if (len % 2 != 0) // If length is not even, word cannot be square
        return 0; // Return false
    for (int i = 0; i < len / 2; i++) { // Loop through first half of word
        if (word[i] != word[i + len / 2]) // If characters don't match across the "square", word is not square
            return 0; // Return false
    }
    return 1; // Return true if all conditions are met
}
