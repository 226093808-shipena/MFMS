#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50
#define STR_LEN 50

// Structure to define what a Supplier contains
typedef struct {
    int supplierID;
    char name[STR_LEN];
    char email[STR_LEN];
    char phone[STR_LEN];
    char location[STR_LEN];
} Supplier;

// Declarations of functions for supplier management
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);
void compareSuppliersByLocation(const Supplier suppliers[], int count);
void supplierMenu();
#endif