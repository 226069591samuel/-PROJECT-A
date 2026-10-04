#include <stdio.h>

int main()
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEmployee Management selected.\n");
        }
        else if (choice == 2)
        {
            printf("\nBudget Management selected.\n");
        }
        else if (choice == 3)
        {
            printf("\nSupplier Management selected.\n");
        }
        else if (choice == 4)
        {
            printf("\nAsset Management selected.\n");
        }
        else if (choice == 5)
        {
            printf("\nReports selected.\n");
        }
        else if (choice == 6)
        {
            printf("\nThank you for using the Municipal Financial Management System.\n");
            printf("Goodbye!\n");
        }
        else
        {
            printf("\nInvalid choice. Please enter a number between 1 and 6.\n");
        }

    } while (choice != 6);

    return 0;
}
