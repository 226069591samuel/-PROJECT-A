#include <stdio.h>
#include <string.h>
#include "reports.h"

void displayEmployeeReport(void) {
    // Array of sample salaries (representing shared data)
    float salaries[5] = {18500.00f, 22000.50f, 12000.00f, 42000.00f, 8500.00f};
    int count = 5; // Array size
    
    float total = 0.0f;
    float highest = salaries[0];
    float lowest = salaries[0];
    
    for (int i = 0; i < count; i++) {
        total += salaries[i];
        
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }
    
    float average = total / count;
    
    printf("\n========================================\n");
    printf("         EMPLOYEE SALARY REPORT          \n");
    printf("========================================\n");
    printf("Total Employees : %d\n", count);
    printf("Total Expenditure: N$%.2f\n", total);
    printf("Average Salary  : N$%.2f\n", average);
    printf("Highest Salary  : N$%.2f\n", highest);
    printf("Lowest Salary   : N$%.2f\n", lowest);
    printf("========================================\n");
}

void displayBudgetReport(void) {
    double totalAllocated = 500000.00;
    double totalSpent = 420000.00;
    double remaining = totalAllocated - totalSpent;
    
    printf("\n========================================\n");
    printf("          BUDGET ANALYSIS REPORT        \n");
    printf("========================================\n");
    printf("Total Allocated Budget : N$%.2f\n", totalAllocated);
    printf("Total Expenditure      : N$%.2f\n", totalSpent);
    printf("Remaining Balance      : N$%.2f\n", remaining);
    
    if (totalSpent > totalAllocated) {
        printf("Status                 : EXCEEDED BUDGET (DEFICIT)\n");
    } else if (totalSpent == totalAllocated) {
        printf("Status                 : BUDGET BALANCED\n");
    } else {
        printf("Status                 : WITHIN BUDGET (SURPLUS)\n");
    }
    printf("========================================\n");
}

void displaySupplierReport(void) {
    // 2D Array to store supplier names and towns
    char supplierNames[3][50] = {"ABC Office Supplies", "Namibia Stationers", "Tech Suppliers"};
    char supplierTowns[3][30] = {"Windhoek", "Walvis Bay", "Swakopmund"};
    
    char search[50];
    int found = 0;
    
    printf("\n========================================\n");
    printf("         REGISTERED SUPPLIERS           \n");
    printf("========================================\n");
    
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%s) - Name Length: %zu chars\n", 
               i + 1, supplierNames[i], supplierTowns[i], strlen(supplierNames[i]));
    }
    printf("----------------------------------------\n");
    
    // Simple supplier search using string comparison
    printf("Enter supplier name to verify: ");
    scanf(" %[^\n]", search); // Reads line including spaces
    
    for (int i = 0; i < 3; i++) {
        if (strcmp(supplierNames[i], search) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Result: Supplier '%s' IS REGISTERED.\n", search);
    } else {
        printf("Result: Supplier '%s' NOT FOUND.\n", search);
    }
    printf("========================================\n");
}

void displayAssetReport(void) {
    printf("\n========================================\n");
    printf("          MUNICIPAL ASSET REPORT        \n");
    printf("========================================\n");
    printf("ID\tAsset Name\t\tType\t\tValue (N$)\n");
    printf("----------------------------------------\n");
    printf("AST01\tToyota Bakkie\t\tVehicle\t\t250000.00\n");
    printf("AST02\tOffice Laptops\t\tComputers\t12000.00\n");
    printf("AST03\tWater Pump\t\tEquipment\t85000.00\n");
    printf("========================================\n");
}

void displayReportsMenu(void) {
    int option;

    do {
        printf("\n========================================\n");
        printf("   MUNICIPAL REPORTS & ANALYTICS MENU   \n");
        printf("========================================\n");
        printf("1. Display Employee Salary Analysis\n");
        printf("2. Display Budget Balance Summary\n");
        printf("3. View and Search Suppliers\n");
        printf("4. Display Municipal Asset Summary\n");
        printf("5. Return to Main Menu\n");
        printf("Enter option (1-5): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayEmployeeReport();
                break;
            case 2:
                displayBudgetReport();
                break;
            case 3:
                displaySupplierReport();
                break;
            case 4:
                displayAssetReport();
                break;
            case 5:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid selection! Please enter a choice between 1 and 5.\n");
        }
    } while (option != 5);
}