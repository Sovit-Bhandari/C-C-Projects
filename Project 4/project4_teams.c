/*
Name = Sovit Bhandari
Discription = This C code takes input for the number of students and their respective points. Based on these points, it assigns each student to one of three teams: 
Beginner, Honor, or Excellence. The code demonstrates use of arrays, pointer arithmetic, and conditional statements for team assignment based on point values.
*/

#include <stdio.h>
#include <stdlib.h>

void assign(int *points, int *team_assignment, int n);

int main() {
    int n;

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input points for each student
    int points[n];
    printf("Enter points for each student: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &points[i]);
    }

    // Array to store team assignment
    int team_assignment[n];

    // Call the assign function
    assign(points, team_assignment, n);

    // Display results
    printf("Beginner team: student");
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 1) {
            printf(" %d", i + 1);
        }
    }
    printf("\nHonor team: student");
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 2) {
            printf(" %d", i + 1);
        }
    }
    printf("\nExcellence team: student");
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 3) {
            printf(" %d", i + 1);
        }
    }
    printf("\n");

    return 0;
}


void assign(int *points, int *team_assignment, int n){
    for (int i = 0; i < n; i++) {
        if (*points<48) {
            *team_assignment = 1;                        // Beginner Team
        } else if (*points>=48 && *points<98) {
            *team_assignment = 2;                        // Honor Team
        } else {
            *team_assignment = 3;                        // Excellence Team
        }

        // Increment pointers using pointer arithmetic
        points++;                                        // Move to the next element in the 'points' array
        team_assignment++;                               // Move to the next element in the 'team_assignment' array
    }
}
