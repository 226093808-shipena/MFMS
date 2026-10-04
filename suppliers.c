#include <stdio.h>
#include <string.h>
#include "suppliers.h"

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("\nSupplier database is full!\n");
        return;
    }

    Supplier s;
    printf("\n=== ADD SUPPLIER ===\n");
    printf("Enter Supplier ID (numbers only): ");
    scanf("%d", &s.supplierID);
    getchar();

    printf("Enter Supplier Name: ");
    fgets(s.name, STR_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = 0; 

    printf("Enter Email: ");
    fgets(s.email, STR_LEN, stdin);
    s.email[strcspn(s.email, "\n")] = 0;

    printf("Enter Phone Number: ");
    fgets(s.phone, STR_LEN, stdin);
    s.phone[strcspn(s.phone, "\n")] = 0;

    printf("Enter Town/Location: ");
    fgets(s.location, STR_LEN, stdin);
    s.location[strcspn(s.location, "\n")] = 0;

    suppliers[*count] = s;
    (*count)++;
    printf("-> Supplier added successfully!\n");
}

void displaySuppliers(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printf("\n=== REGISTERED SUPPLIERS ===\n");
    printf("%-10s %-20s %-20s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Location");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-20s %-15s %-15s\n", 
               suppliers[i].supplierID, 
               suppliers[i].name, 
               suppliers[i].email, 
               suppliers[i].phone, 
               suppliers[i].location);
    }
}

void searchSupplier(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers available to search.\n");
        return;
    }

    char searchName[STR_LEN];
    printf("\nEnter Supplier Name to search: ");
    getchar();
    fgets(searchName, STR_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("\nSupplier Found!\n");
            printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\nLocation: %s\n",
                   suppliers[i].supplierID, suppliers[i].name, 
                   suppliers[i].email, suppliers[i].phone, suppliers[i].location);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Supplier '%s' was not found.\n", searchName);
    }
}

void compareSuppliersByLocation(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers available.\n");
        return;
    }

    char targetLocation[STR_LEN];
    printf("\nEnter Town/Location to filter: ");
    getchar();
    fgets(targetLocation, STR_LEN, stdin);
    targetLocation[strcspn(targetLocation, "\n")] = 0;

    printf("\n=== SUPPLIERS IN %s ===\n", targetLocation);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(suppliers[i].location, targetLocation) == 0) {
            printf("- ID: %d | Name: %s | Phone: %s\n", 
                   suppliers[i].supplierID, suppliers[i].name, suppliers[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("No suppliers found in '%s'.\n", targetLocation);
    }
}