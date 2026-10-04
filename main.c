#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int main() {
    int choice;

    do {
        printf("\n===========================================\n");
        printf("  Municipal Financial Management System    \n");
        printf("===========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n[employee module]\n");
                break;
            case 2:
                printf("\n[budget module]\n");
                break;
            case 3:
                supplierMenu();
                break;
            case 4:
                assetMenu();
                break;
            case 5:
                printf("\n[Reports module]\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while(choice != 6);

    return 0;
}
