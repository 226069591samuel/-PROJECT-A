#include <stdio.h>
#include <string.h>

int main()
{
    int supplierID[100];
    char supplierName[100][50];
    char supplierEmail[100][50];
    char supplierTelephone[100][20];
    char supplierLocation[100][50];

    int numberOfSuppliers;
    int i;
    int found;
    int supplier1;
    int supplier2;
    char search[50];

    // Add Supplier

    printf("Enter number of suppliers: ");
    scanf("%d", &numberOfSuppliers);

    for (i = 0; i < numberOfSuppliers; i++)
    {
        printf("\nEnter details for supplier %d\n", i + 1);

        printf("Enter supplier ID: ");
        scanf("%d", &supplierID[i]);

        printf("Enter supplier name: ");
        scanf("%s", supplierName[i]);

        printf("Enter supplier email: ");
        scanf("%s", supplierEmail[i]);

        printf("Enter supplier telephone: ");
        scanf("%s", supplierTelephone[i]);

        printf("Enter supplier location: ");
        scanf("%s", supplierLocation[i]);
    }

    // Display Suppliers

    printf("\n--- Supplier Information ---\n");

    for (i = 0; i < numberOfSuppliers; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %d\n", supplierID[i]);
        printf("Supplier Name: %s\n", supplierName[i]);
        printf("Supplier Email: %s\n", supplierEmail[i]);
        printf("Supplier Telephone: %s\n", supplierTelephone[i]);
        printf("Supplier Location: %s\n", supplierLocation[i]);
    }

    // Search Supplier

    found = 0;

    printf("\nEnter supplier name to search: ");
    scanf("%s", search);

    for (i = 0; i < numberOfSuppliers; i++)
    {
        if (strcmp(supplierName[i], search) == 0)
        {
            printf("\nSupplier found\n");
            printf("Supplier ID: %d\n", supplierID[i]);
            printf("Supplier Name: %s\n", supplierName[i]);
            printf("Supplier Email: %s\n", supplierEmail[i]);
            printf("Supplier Telephone: %s\n", supplierTelephone[i]);
            printf("Supplier Location: %s\n", supplierLocation[i]);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nSupplier not found.\n");
    }

    // Compare Supplier Information

    if (numberOfSuppliers >= 2)
    {
        printf("\n--- Compare Supplier Information ---\n");

        printf("Enter first supplier number: ");
        scanf("%d", &supplier1);

        printf("Enter second supplier number: ");
        scanf("%d", &supplier2);

        if (supplier1 < 1 || supplier1 > numberOfSuppliers ||
            supplier2 < 1 || supplier2 > numberOfSuppliers)
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

            if (strcmp(supplierName[supplier1 - 1],
                       supplierName[supplier2 - 1]) == 0)
            {
                printf("Supplier names are the same.\n");
            }
            else
            {
                printf("Supplier names are different.\n");
            }

            if (strcmp(supplierEmail[supplier1 - 1],
                       supplierEmail[supplier2 - 1]) == 0)
            {
                printf("Supplier emails are the same.\n");
            }
            else
            {
                printf("Supplier emails are different.\n");
            }

            if (strcmp(supplierTelephone[supplier1 - 1],
                       supplierTelephone[supplier2 - 1]) == 0)
            {
                printf("Supplier telephone numbers are the same.\n");
            }
            else
            {
                printf("Supplier telephone numbers are different.\n");
            }

            if (strcmp(supplierLocation[supplier1 - 1],
                       supplierLocation[supplier2 - 1]) == 0)
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

    return 0;
}