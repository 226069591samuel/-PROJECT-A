#include <stdio.h>
#include "main.h"

// Menu display
void displayMenu() {
    printf("\nMUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Validation for positive numbers (salary, budget, etc.)
int validatePositive(double value) {
    if (value < 0) {
        printf("Error: Value cannot be negative!\n");
        return 0; // invalid
    }
    return 1; // valid
}

// Validation for menu choice
int validateMenuChoice(int choice) {
    if (choice < 1 || choice > 6) {
        printf("Invalid choice. Please try again.\n");
        return 0;
    }
    return 1;
}

// System integration
void runSystem() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        if (!validateMenuChoice(choice)) {
            continue; // re-prompt until valid
        }

        switch(choice) {
            case 1: 
                printf("Employee Management Module...\n");
                break;
            case 2: 
                printf("Budget Management Module...\n");
                break;
            case 3: 
                printf("Supplier Management Module...\n");
                break;
            case 4: 
                printf("Asset Management Module...\n");
                break;
            case 5: 
                printf("Reports Module...\n");
                break;
            case 6: 
                printf("Exiting system...\n");
                break;
        }
    } while(choice != 6);
}

// Entry point
int main() {
    runSystem();
    return 0;
}