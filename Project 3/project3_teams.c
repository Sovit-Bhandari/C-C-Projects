/*
Name = Sovit Bhandari
Discription = This code assigns students to different teams according to their performance points. First, the program inputs the number of
students along with their performance points. Then, it uses the function assign to assign each student to a different team based on how close 
they are to predefined thresholds.
*/

#include <stdio.h>
#include <stdlib.h>

void assign(int points[], int team_assignment[], int n);

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

// Implementation of the assign function
void assign(int points[], int team_assignment[], int n) {
    for (int i = 0; i < n; i++) {
// Calculate the difference of performance points from predefined thresholds
        int diff_beginner = abs(points[i] - 25);
        int diff_honor = abs(points[i] - 70);
        int diff_excellence = abs(points[i] - 125);
// Assign the student to the team with the minimum difference
        if (diff_beginner <= diff_honor && diff_beginner <= diff_excellence) {
            team_assignment[i] = 1;  // Beginner team
        } else if (diff_honor <= diff_beginner && diff_honor <= diff_excellence) {
            team_assignment[i] = 2;  // Honor team
        } else {
            team_assignment[i] = 3;  // Excellence team
        }
    }
}
