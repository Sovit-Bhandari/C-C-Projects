/*
Name = Sovit Bhandari
Description = The following code is a simple c program code that calculates charges for different 
packages based on user input for hours and the number of guests. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int package, hours, guest, charge;
    
    printf("Please select from three packages: 1, 2, and 3\n");
    printf("Enter package selection:");
    scanf("%d", &package);                                             // Allowing user for package selection

    if (package >= 1 && package <= 3){
        if (package==1){                                               // conditions for package 1 and charge calculation
            printf("Enter hours:");                           
            scanf("%d", &hours);                                        // User input for hours
            if (hours >= 1 && hours<=4){
                printf("Enter the number of guests: ");
                scanf("%d", &guest);                                    // User input for number of guests
                if (guest >= 5 && guest <=20){
                    charge = 150 + (hours-1)*100 + guest*25 ;           // formula for calculation charge
                        if (charge<=595) {
                            printf("Charge($):%d\n", charge);
                        }
                        else
                            printf("Charge($):595\n");
                }
                else
                    printf("Invalid number of guests.");
            }
            else
                printf("Invalid hours.");
        }


        else if (package==2){                                           // conditions for package 2 and charge calculation
            printf("Enter hours:");
            scanf("%d", &hours);                                        // User input for hours
            if (hours >= 1 && hours<=4){
                printf("Enter the number of guests: ");
                scanf("%d", &guest);                                    // User input for number of guests
                if (guest >= 8 && guest <=30){
                    charge = 180 + (hours-1)*120 + guest*22 ;           // formula for calculation charge
                    if (charge<=850) {
                            printf("Charge($):%d\n", charge);
                        }
                        else
                            printf("Charge($):850\n");
                }
                else
                    printf("Invalid number of guests.");
            }
            else
                printf("Invalid hours.");
        }


        else if (package==3){                                            // conditions for package 3 and charge calculation
            printf("Enter hours:");
            scanf("%d", &hours);                                         // User input for hours
            if (hours >= 1 && hours<=4){
                printf("Enter the number of guests: ");
                scanf("%d", &guest);                                     // User input for number of guests
                if (guest >= 10 && guest <=40){
                    charge = 200 + (hours-1)*150 + guest*20 ;            // formula for calculation charge
                    if (charge<=1050) {
                            printf("Charge($):%d\n", charge);
                        }
                        else
                            printf("Charge($):1050\n");
                }
                else
                    printf("Invalid number of guests.");
            }
            else
                printf("Invalid hours.");
        }

    }
    else
        printf("Invalid selection.");
    return 0;

} 

