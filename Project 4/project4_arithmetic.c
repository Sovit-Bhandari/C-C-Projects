/*
Name = Sovit Bhandari
U-Id= U83561265
Discription = This C program determines whether a sequence of integers entered by the user forms an arithmetic sequence. it checks if the sequence is arithmetic by
comparing the differences between consecutive elements. If the differences are consistent throughout the sequence, it prints yes. otherwise it prints no.

*/

#include <stdio.h>

int is_arithmetic_sequence(int *sequence, int n);

int main() {
    int n;
    printf("Enter length of the sequence: ");
    scanf("%d", &n);

    int sequence[n];
    printf("Enter numbers of the sequence: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sequence[i]);
    }

// Checking if the entered sequence is an arithmetic sequence
    if (is_arithmetic_sequence(sequence, n))
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}

// Funtion for testing arithmetic sequence
int is_arithmetic_sequence(int *sequence, int n) {
    if (n <= 2)
        return 1; // Trivially arithmetic if there are 0 or 1 elements

    int difference = *sequence - *(sequence + 1); // Calculate the difference between the first two elements

    for (int i = 1; i < n - 1; ++i) {
        if (*(sequence + i) - *(sequence + i + 1) != difference)
            return 0; // Not an arithmetic sequence
    }

    return 1; // It's an arithmetic sequence
}
