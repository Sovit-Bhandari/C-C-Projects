/*
Name = Sovit Bhandari
Description = This is a C program that mimics a vending machine. It will ask you to put in coins until you enter 0
(meaning until you stop putting money).Then, it will show you the total amount of coins and give you a candy menu to choose from.
The program will calculate change based on your candy selection and tell you if the amount you have put in is not enough or if 
your candy selection is invalid.
*/

#include <stdio.h>

// Define constants for the prices of different items
#define Hershey 15
#define Reese 25
#define Snickers 50


int main(){
    // Declare variables for coins, choice, and change
    int coin, choice, change;
    int amount=0;

    coin = 1;                                                                       // Initialize coin to a non-zero value to enter the loop
    while (coin!=0){                                                                // Continue accepting coins until user enters 0
        printf("Insert coins:");
        scanf("%d", &coin);
        amount = amount + coin;                                                     // Add the entered coin to the total amount
    }


    // Display the menu for item choices
    printf("1 - Hershey's kisses (15 cents), 2 - Reese's Peanut Butter Cups (25 cents), 3 - Snickers (50 cents)\n");
    printf("Enter your choice:");
    scanf("%d", &choice);

    // Check the user's choice and calculate the change
    if (choice ==1){
        change = amount - Hershey;                                                   // Check if the user provided enough money for the selected item
        if (change>=0){
            printf("Your change is %d cents\n", change);
        }
        else 
            printf("Insufficient amount, %d cents returned\n", amount);

    }

    else if (choice ==2){
        change = amount - Reese;
        if (change>=0){
            printf("Your change is %d cents\n", change);
        }
        else 
            printf("Insufficient amount, %d cents returned\n", amount);
    }  

    else if (choice ==3){
        change = amount - Snickers;
        if (change>=0){
            printf("Your change is %d cents\n", change);
        }
        else 
            printf("Insufficient amount, %d cents returned\n", amount);
    }
    
    else
        printf("Invalid selection, %d cents returned\n", amount);                   // If an invalid selection is made, return the entered amount
    return 0;
}



