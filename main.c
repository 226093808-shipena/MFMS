#include <stdio.h>
#include <stdlib.h>
#include "validation.h"

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

void displayMainMenu(void) {
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

int main(void) {
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