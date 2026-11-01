#include <stdio.h>
#include <string.h>
#include "assets.h"

/* Asset data: the same position in every array = one asset */
char   assetID[MAX_ASSETS][ID_LEN];
char   assetName[MAX_ASSETS][NAME_LEN];
char   assetType[MAX_ASSETS][TEXT_LEN];
double assetValue[MAX_ASSETS];
char   assetDept[MAX_ASSETS][NAME_LEN];
char   assetCondition[MAX_ASSETS][TEXT_LEN];
int    assetCount = 0;      /* how many assets have been added */

/* Throw away wrong input (for example letters typed instead of a number) */
void clearAssetInput(void)
{
    while (getchar() != '\n')
        ;
}

void addAsset(void)
{
    char id[ID_LEN];
    int i, choice;

    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset register is full.\n");
        return;
    }

    printf("Asset ID (no spaces): ");
    scanf("%14s", id);

    /* check that the ID is not used already */
    for (i = 0; i < assetCount; i++)
    {
        if (strcmp(id, assetID[i]) == 0)
        {
            printf("This ID already exists.\n");
            return;
        }
    }
    strcpy(assetID[assetCount], id);

    printf("Asset name (one word): ");
    scanf("%49s", assetName[assetCount]);

    printf("Asset type (e.g. Vehicle, Computer): ");
    scanf("%29s", assetType[assetCount]);

    /* value must be a number above 0 */
    do
    {
        printf("Purchase value (N$): ");
        if (scanf("%lf", &assetValue[assetCount]) != 1)
        {
            clearAssetInput();
            assetValue[assetCount] = 0;
        }
        if (assetValue[assetCount] <= 0)
            printf("Value must be a number above 0.\n");
    } while (assetValue[assetCount] <= 0);

    printf("Department (one word): ");
    scanf("%49s", assetDept[assetCount]);

    /* condition must be 1, 2 or 3 */
    do
    {
        printf("Condition (1=Good, 2=Fair, 3=Poor): ");
        if (scanf("%d", &choice) != 1)
        {
            clearAssetInput();
            choice = 0;
        }
        if (choice < 1 || choice > 3)
            printf("Please enter 1, 2 or 3.\n");
    } while (choice < 1 || choice > 3);

    if (choice == 1)
        strcpy(assetCondition[assetCount], "Good");
    else if (choice == 2)
        strcpy(assetCondition[assetCount], "Fair");
    else
        strcpy(assetCondition[assetCount], "Poor");

    assetCount++;
    printf("Asset added.\n");
}

void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("No assets yet.\n");
        return;
    }

    printf("\nID    Name    Type    Value    Department    Condition\n");
    for (i = 0; i < assetCount; i++)
    {
        printf("%s  %s  %s  N$%.2f  %s  %s\n",
               assetID[i], assetName[i], assetType[i],
               assetValue[i], assetDept[i], assetCondition[i]);
    }
}

void searchAsset(void)
{
    char key[NAME_LEN];
    int i, found = 0;

    printf("Enter asset ID or name to search: ");
    scanf("%49s", key);

    for (i = 0; i < assetCount; i++)
    {
        if (strcmp(key, assetID[i]) == 0 || strcmp(key, assetName[i]) == 0)
        {
            printf("%s  %s  %s  N$%.2f  %s  %s\n",
                   assetID[i], assetName[i], assetType[i],
                   assetValue[i], assetDept[i], assetCondition[i]);
            found = 1;
        }
    }

    if (found == 0)
        printf("Asset not found.\n");
}

void assetReport(void)
{
    int i, poor = 0;
    double total = 0;

    for (i = 0; i < assetCount; i++)
    {
        total = total + assetValue[i];
        if (strcmp(assetCondition[i], "Poor") == 0)
            poor++;
    }

    printf("\n--- ASSET REPORT ---\n");
    printf("Total assets: %d\n", assetCount);
    printf("Total value: N$%.2f\n", total);
    printf("Assets in poor condition: %d\n", poor);
}

void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add asset\n");
        printf("2. Display assets\n");
        printf("3. Search asset\n");
        printf("4. Asset report\n");
        printf("5. Back to main menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            clearAssetInput();
            choice = 0;
        }

        switch (choice)
        {
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAsset();   break;
            case 4: assetReport();   break;
            case 5: printf("Going back...\n"); break;
            default: printf("Invalid choice. Enter 1-5.\n");
        }
    } while (choice != 5);
}
