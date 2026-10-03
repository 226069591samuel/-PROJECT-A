#ifndef SUPPLIERMANAGEMENT_H
#define SUPPLIERMANAGEMENT_H

#define MAX 100

struct Supplier
{
    int supplierID;
    char supplierName[50];
    char supplierEmail[50];
    char supplierTelephone[20];
    char supplierLocation[50];
};

void addSupplier();
void displaySuppliers();
void searchSupplier();
void compareSuppliers();

#endif
