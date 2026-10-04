#ifndef SEARCH_H
#define SEARCH_H

typedef struct {
    int id;
    char name[50];
    char category[50];
} SearchItem;

// Function declarations
void searchByName(SearchItem items[], int count, const char *searchName);
void searchById(SearchItem items[], int count, int searchId);

#endif