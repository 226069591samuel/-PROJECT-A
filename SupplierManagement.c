#include <stdio.h>
#include <string.h>
#include "SupplierManagement.h"

struct Supplier suppliers[MAX];
int supplierCount = 0;

// Add Supplier

void addSupplier()
{
    printf("Enter number of suppliers: ");
    scanf("%d", &supplierCount);

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nEnter details for supplier %d\n", i + 1);

        printf("Enter supplier ID: ");
        scanf("%d", &suppliers[i].supplierID);

        printf("Enter supplier name: ");
        scanf("%s", suppliers[i].supplierName);

        printf("Enter supplier email: ");
        scanf("%s", suppliers[i].supplierEmail);

        printf("Enter supplier telephone: ");
        scanf("%s", suppliers[i].supplierTelephone);

        printf("Enter supplier location: ");
        scanf("%s", suppliers[i].supplierLocation);
    }
}

// Display Suppliers

void displaySuppliers()
{
    printf("\n--- Supplier Information ---\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %d\n", suppliers[i].supplierID);
        printf("Supplier Name: %s\n", suppliers[i].supplierName);
        printf("Supplier Email: %s\n", suppliers[i].supplierEmail);
        printf("Supplier Telephone: %s\n", suppliers[i].supplierTelephone);
        printf("Supplier Location: %s\n", suppliers[i].supplierLocation);
    }
}

// Search Supplier

void searchSupplier()
{
    int found = 0;
    char search[50];

    printf("\nEnter supplier name to search: ");
    scanf("%s", search);

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].supplierName, search) == 0)
        {
            printf("\nSupplier found\n");
            printf("Supplier ID: %d\n", suppliers[i].supplierID);
            printf("Supplier Name: %s\n", suppliers[i].supplierName);
            printf("Supplier Email: %s\n", suppliers[i].supplierEmail);
            printf("Supplier Telephone: %s\n", suppliers[i].supplierTelephone);
            printf("Supplier Location: %s\n", suppliers[i].supplierLocation);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nSupplier not found.\n");
    }
}

// Compare Supplier Information

void compareSuppliers()
{
    int supplier1;
    int supplier2;

    if (supplierCount >= 2)
    {
        printf("\n--- Compare Supplier Information ---\n");

        printf("Enter first supplier number: ");
        scanf("%d", &supplier1);

        printf("Enter second supplier number: ");
        scanf("%d", &supplier2);

        if (supplier1 < 1 || supplier1 > supplierCount ||
            supplier2 < 1 || supplier2 > supplierCount)
        {
            printf("\nInvalid supplier number.\n");
        }
        else if (supplier1 == supplier2)
        {
            printf("\nPlease choose two different suppliers.\n");
        }
        else
        {
            printf("\nComparing Supplier %d and Supplier %d\n",
                   supplier1, supplier2);

            if (strcmp(suppliers[supplier1 - 1].supplierName,
                       suppliers[supplier2 - 1].supplierName) == 0)
            {
                printf("Supplier names are the same.\n");
            }
            else
            {
                printf("Supplier names are different.\n");
            }

            if (strcmp(suppliers[supplier1 - 1].supplierEmail,
                       suppliers[supplier2 - 1].supplierEmail) == 0)
            {
                printf("Supplier emails are the same.\n");
            }
            else
            {
                printf("Supplier emails are different.\n");
            }

            if (strcmp(suppliers[supplier1 - 1].supplierTelephone,
                       suppliers[supplier2 - 1].supplierTelephone) == 0)
            {
                printf("Supplier telephone numbers are the same.\n");
            }
            else
            {
                printf("Supplier telephone numbers are different.\n");
            }

            if (strcmp(suppliers[supplier1 - 1].supplierLocation,
                       suppliers[supplier2 - 1].supplierLocation) == 0)
            {
                printf("Supplier locations are the same.\n");
            }
            else
            {
                printf("Supplier locations are different.\n");
            }
        }
    }
    else
    {
        printf("\nAt least two suppliers are needed for comparison.\n");
    }
}
