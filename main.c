#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int getValidIntOption(int min, int max) {
    int choice;
    while (1) {
        printf("Enter your choice (%d-%d): ", min, max);
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max) {
            while (getchar() != '\n'); 
            return choice;
        } else {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); 
        }
    }
}

void displayMainMenu() {
    printf("\n===========================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM   \n");
    printf("===========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("===========================================\n");
}

int main() {
    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;

    int choice;

    do {
        displayMainMenu();
        choice = getValidIntOption(1, 6);

        switch (choice) {
            case 1:
                printf("\n--- EMPLOYEE MANAGEMENT ---\n");
                break;
            case 2:
                printf("\n--- BUDGET MANAGEMENT ---\n");
                break;
            case 3:
                printf("\n--- SUPPLIER MANAGEMENT ---\n");
                printf("1. Add Supplier\n2. Display Suppliers\n3. Search Supplier\n4. Compare Locations\nEnter option: ");
                int supChoice = getValidIntOption(1, 4);
                if (supChoice == 1) addSupplier(suppliers, &supplierCount);
                else if (supChoice == 2) displaySuppliers(suppliers, supplierCount);
                else if (supChoice == 3) searchSupplier(suppliers, supplierCount);
                else if (supChoice == 4) compareSuppliersByLocation(suppliers, supplierCount);
                break;
            case 4:
                printf("\n--- ASSET MANAGEMENT ---\n");
                break;
            case 5:
                printf("\n--- REPORTS ---\n");
                break;
            case 6:
                printf("\nExiting Municipal Financial Management System. Goodbye!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}