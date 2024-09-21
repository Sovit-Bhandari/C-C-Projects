/*
Name = Sovit Bhandari
U-Id = U83561265
Description = This program analyzes the user’s input by looking at each character. It checks whether each character matches the 
lowercase letters, digits, spaces, exclamation marks, question marks, or periods. If a character does not match, it is considered 
invalid. Otherwise, it is considered valid.
*/

#include <stdio.h>
#include <ctype.h>

int main(){
    char ch;
    char valid = 1;                                      // Initialize a flag variable 'valid' to 1, assuming the input is initially valid.
    
    printf("Enter input:");
    while ((ch = getchar())!= '\n'){                    // Enter a loop that continues until the user presses Enter.
        if (!(islower(ch) || isdigit(ch) || ch=='!' || ch==' ' || ch=='?' || ch=='.')){       // Condition for a input to be true
            valid = 0;
        }
    }

    if (!valid){                                        // Check the 'valid' flag to determine if the input is valid or not.
        printf("invalid");
    } 
    else {
        printf("valid");
    }
    return 0;
} 