#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assets.h"

/* ---------- Asset data stored in parallel arrays ---------- */
static char   assetID[MAX_ASSETS][ID_LEN];
static char   assetName[MAX_ASSETS][NAME_LEN];
static char   assetType[MAX_ASSETS][TEXT_LEN];
static double assetValue[MAX_ASSETS];
static char   assetDept[MAX_ASSETS][NAME_LEN];
static char   assetCondition[MAX_ASSETS][TEXT_LEN];
static int    assetCount = 0;

/* ---------- Helper functions ---------- */

/* Read a line of text and remove the newline */
static void readString(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

/* Read a whole number safely */
static int readInt(void)
{
    char line[50];
    int number;

    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &number) != 1)
        return -1;               /* invalid input */
    return number;
}

/* Read a positive money value */
static double readValue(void)
{
    char line[50];
    double value;

    while (1)
    {
        printf("Purchase value (N$): ");
        fgets(line, sizeof(line), stdin);

        if (sscanf(line, "%lf", &value) != 1)
            printf("Invalid number. Try again.\n");
        else if (value <= 0)
            printf("Value must be greater than 0.\n");
        else
            return value;
    }
}

/* Read text that must not be empty */
static void readRequired(const char prompt[], char text[], int size)
{
    while (1)
    {
        printf("%s", prompt);
        readString(text, size);

        if (strlen(text) == 0)
            printf("This field cannot be empty.\n");
        else
            return;
    }
}

/* Return index of asset with this ID, or -1 if not found */
static int findAssetByID(const char id[])
{
    int i;
    for (i = 0; i < assetCount; i++)
    {
        if (strcmp(assetID[i], id) == 0)
            return i;
    }
    return -1;
}

/* Print one asset */
static void printAsset(int i)
{
    printf("%-10s %-20s %-16s %12.2f  %-15s %-12s\n",
           assetID[i], assetName[i], assetType[i],
           assetValue[i], assetDept[i], assetCondition[i]);
}

static void printHeader(void)
{
    printf("\n%-10s %-20s %-16s %12s  %-15s %-12s\n",
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("--------------------------------------------------------------------------------------\n");
}

/* ---------- Main asset functions ---------- */

void addAsset(void)
{
    char id[ID_LEN];
    int choice;

    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset register is full.\n");
        return;
    }

    printf("\n--- ADD ASSET ---\n");

    /* Asset ID (must be unique) */
    readRequired("Asset ID: ", id, ID_LEN);
    if (findAssetByID(id) != -1)
    {
        printf("An asset with this ID already exists.\n");
        return;
    }
    strcpy(assetID[assetCount], id);

    /* Asset name */
    readRequired("Asset name: ", assetName[assetCount], NAME_LEN);

    /* Asset type */
    do
    {
        printf("Asset type:\n");
        printf(" 1. Vehicle\n 2. Computer\n 3. Building\n");
        printf(" 4. Equipment\n 5. Office Furniture\n");
        printf("Choose (1-5): ");
        choice = readInt();

        switch (choice)
        {
            case 1: strcpy(assetType[assetCount], "Vehicle");          break;
            case 2: strcpy(assetType[assetCount], "Computer");         break;
            case 3: strcpy(assetType[assetCount], "Building");         break;
            case 4: strcpy(assetType[assetCount], "Equipment");        break;
            case 5: strcpy(assetType[assetCount], "Office Furniture"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice < 1 || choice > 5);

    /* Purchase value */
    assetValue[assetCount] = readValue();

    /* Department */
    readRequired("Department: ", assetDept[assetCount], NAME_LEN);

    /* Condition */
    do
    {
        printf("Condition:\n");
        printf(" 1. Good\n 2. Fair\n 3. Poor\n");
        printf("Choose (1-3): ");
        choice = readInt();

        if (choice == 1)      strcpy(assetCondition[assetCount], "Good");
        else if (choice == 2) strcpy(assetCondition[assetCount], "Fair");
        else if (choice == 3) strcpy(assetCondition[assetCount], "Poor");
        else                  printf("Invalid choice.\n");
    } while (choice < 1 || choice > 3);

    assetCount++;
    printf("Asset added successfully.\n");
}

void displayAssets(void)
{
    int i;

    printf("\n--- ASSET REGISTER ---\n");

    if (assetCount == 0)
    {
        printf("No assets registered yet.\n");
        return;
    }

    printHeader();
    for (i = 0; i < assetCount; i++)
        printAsset(i);
}

void searchAsset(void)
{
    char key[NAME_LEN];
    int choice, i, found = 0;

    printf("\n--- SEARCH ASSET ---\n");
    printf("1. Search by Asset ID\n");
    printf("2. Search by Asset name\n");
    printf("Choose: ");
    choice = readInt();

    if (choice == 1)
    {
        readRequired("Enter Asset ID: ", key, NAME_LEN);
        i = findAssetByID(key);

        if (i == -1)
            printf("Asset not found.\n");
        else
        {
            printHeader();
            printAsset(i);
        }
    }
    else if (choice == 2)
    {
        readRequired("Enter name (or part of it): ", key, NAME_LEN);

        for (i = 0; i < assetCount; i++)
        {
            if (strstr(assetName[i], key) != NULL)
            {
                if (!found)
                    printHeader();
                printAsset(i);
                found = 1;
            }
        }
        if (!found)
            printf("No matching assets found.\n");
    }
    else
        printf("Invalid choice.\n");
}

void assetReport(void)
{
    int i, poorCount = 0;
    double total = 0;

    printf("\n========== ASSET REPORT ==========\n");

    if (assetCount == 0)
    {
        printf("No assets registered yet.\n");
        return;
    }

    printHeader();
    for (i = 0; i < assetCount; i++)
    {
        printAsset(i);
        total += assetValue[i];
        if (strcmp(assetCondition[i], "Poor") == 0)
            poorCount++;
    }

    printf("\nTotal assets         : %d\n", assetCount);
    printf("Total purchase value : N$%.2f\n", total);
    printf("Assets in poor condition: %d\n", poorCount);
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
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        choice = readInt();

        switch (choice)
        {
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAsset();   break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please enter 1-4.\n");
        }
    } while (choice != 4);
}   