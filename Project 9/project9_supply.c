/*
Name = Sovit Bhandari
U-Id= U83561265
Discription = This C program reads supply information from a CSV file, sorts the supplies alphabetically by name and then by color, and writes the 
sorted data to another CSV file. It defines a structure to hold supply details, including name, color, and quantity. The program uses a comparison function 
and the 'qsort' function to sort the supplies. File handling functions are used to read from and write to files. Finally, it prints a message indicating 
successful completion.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUPPLIES 200
#define MAX_NAME_LENGTH 100
#define MAX_COLOR_LENGTH 100

struct supply {
    char name[MAX_NAME_LENGTH];                                                     // Define a structure to hold supply information, including name, color, and quantity
    char color[MAX_COLOR_LENGTH];
    int quantity;
};

// Comparison function for qsort
int compare_supplies(const void *a, const void *b) {                                // Define a comparison function for sorting supplies
    const struct supply *supply_a = (const struct supply *)a;                        // Cast the void pointers to supply pointers
    const struct supply *supply_b = (const struct supply *)b;
    
    // First, compare by name
    int name_cmp = strcmp(supply_a->name, supply_b->name);                          // Compare names of supplies
    if (name_cmp != 0)                                                              // If names are not the same, return the result of the name comparison
        return name_cmp;
    
    // If names are same, compare by color
    return strcmp(supply_a->color, supply_b->color);                                // If names are the same, compare colors of supplies
}

int main() {
    FILE *input_file = fopen("supply.csv", "r");                                    // Open input file for reading
    FILE *output_file = fopen("result.csv", "w");                                   // Open output file for writing

    if (input_file == NULL || output_file == NULL) {                                // Check if files were opened successfully
        printf("Error opening files.\n");                                           // Print error message if opening files failed
        return 1;                                                                   // Exit program with error code
    }

    struct supply supplies[MAX_SUPPLIES];                                           // Declare an array to hold supply data
    int num_supplies = 0;                                                           // Initialize a variable to count the number of supplies read

    // Read supplies from file
    while (fscanf(input_file, "%[^,], %[^,], %d\n", supplies[num_supplies].name,
                  supplies[num_supplies].color, &supplies[num_supplies].quantity) == 3) {  // Read supply information from file
        num_supplies++;                                                                     // Increment the count of supplies read
    }

    fclose(input_file);                                                                     // Close input file after reading

    // Sort supplies using quicksort
    qsort(supplies, num_supplies, sizeof(struct supply), compare_supplies);                 // Sort supplies array using quicksort algorithm

    // Write sorted supplies to output file
    for (int i = 0; i < num_supplies; ++i) {                                                // Loop through sorted supplies
        fprintf(output_file, "%s, %s, %d\n", supplies[i].name, supplies[i].color, supplies[i].quantity);  // Write supply information to output file
    }

    fclose(output_file);                                                                    // Close output file after writing
    printf("Supplies sorted and written to result.csv.\n");                                 // Print message indicating successful completion

    return 0;                                                                               // Exit program with success code
}
