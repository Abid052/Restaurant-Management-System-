#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "login.h"
#include "splash.h"


int main(void) {
     printDesign();
     int choice;
     registerUser();
     loginUser();

    while (1) {
        printf("\n--------------------------------Welcome to the Restaurant ----------------------------------------\n");
        printf(" \n------------HERE WE SELL HEALTHY , FRESH AND TASTY FOOD AS YOU PREFER-----------\n\n");
        printf("1. Display Menu  :\n");
        printf("2. Place Order   :\n");
        printf("3. Generate Bill :\n");
        printf("4. Exit          :\n");

        printf("Enter your choice Between 1 to 5 : ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                display_menu();//calling function
                break;
            case 2:
                place_order();
                break;
            case 3:
                generate_bill();
                break;
            case 4:
                printf("Thank you for visiting.Hope you enjoyed our service . come back again :)!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

