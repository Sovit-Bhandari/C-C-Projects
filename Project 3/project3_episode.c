/*
Name = Sovit Bhandari
U-Id= U83561265
Discription = This C program is used to find the missing episode number from a series of episodes. It will ask you to enter your total 
number of episodes. After that, it will ask you for the episodes you have already watched. Based on the answers given, it will locate 
the missing episode of the series.
*/

#include <stdio.h>

int main() {
    int n, i, j;
    int ep;

    printf("Enter number of episodes: ");
    scanf("%d", &n);

// Declaring array 'a' to store all episode numbers
    int a[n];
// Initializing array 'a' with sequential episode numbers
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    printf("Enter episodes watched: ");
// Declare an array 'b' to store the watched episode numbers
    int b[n - 1];
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &b[i]);
    }

// Declaring variable 'found' to track whether a particular episode is found in the watched list
    int found;
// Loop through all episodes to find the missing one
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < n - 1; j++) {
            if (a[i] == b[j]) {
                found = 1;
                break;
            }
        }
// If the current episode is not found in the watched list we assign it to ep and break the loop
        if (!found) {
            ep = a[i];
            break;
        }
    }

// Output the missing episode
    printf("Missing episode: %d\n", ep);

    return 0;
}
