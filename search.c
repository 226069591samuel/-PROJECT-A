#include <stdio.h>
#include <string.h>
#include "search.h"

void searchByName(SearchItem items[], int count, const char *searchName) {
    int found = 0;
    printf("\n--- SEARCH RESULTS FOR: '%s' ---\n", searchName);
    for (int i = 0; i < count; i++) {
        if (strstr(items[i].name, searchName) != NULL) {
            printf("ID: %d | Name: %s | Category: %s\n", items[i].id, items[i].name, items[i].category);
            found = 1;
        }
    }
    if (!found) {
        printf("No records found matching '%s'.\n", searchName);
    }
    printf("----------------------------------\n");
}

void searchById(SearchItem items[], int count, int searchId) {
    int found = 0;
    printf("\n--- SEARCH RESULTS FOR ID: %d ---\n", searchId);
    for (int i = 0; i < count; i++) {
        if (items[i].id == searchId) {
            printf("ID: %d | Name: %s | Category: %s\n", items[i].id, items[i].name, items[i].category);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No record found with ID %d.\n", searchId);
    }
    printf("----------------------------------\n");
}