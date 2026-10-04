// budget.c
//Budget Management module for the MFMS project (PAP521S Project A)
//This file handles department budgets, expenditure, and over-budget reporting.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "budget.h"

/* ================================================================== */
/*  Internal Helper Functions (static - not exposed in header)         */
/* ================================================================== */

//Reads one line of input and removes the trailing newline character
//  Returns 1 on success, 0 on error or end of input
static int readLine(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) == NULL) {
        return 0;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

// Reads a non-negative decimal number from input
// Validates that it is a real number and non-negative
static int readNonNegativeDouble(const char *prompt, double *result)
{
    char   line[64];
    char  *endPtr;
    double value;

    while (1) {
        printf("%s", prompt);

        if (!readLine(line, sizeof(line))) {
            return 0; /* EOF or error */
        }

        if (strlen(line) == 0) {
            printf("[!] Input cannot be empty. Please try again.\n");
            continue;
        }

        value = strtod(line, &endPtr);

        /* Reject if no digits were consumed or trailing garbage exists */
        if (endPtr == line || *endPtr != '\0') {
            printf("[!] Invalid number. Please enter a numeric value.\n");
            continue;
        }

        if (value < 0.0) {
            printf("[!] Value cannot be negative. Please try again.\n");
            continue;
        }

        *result = value;
        return 1;
    }
}

/* ================================================================== */
/*  Public Function Implementations                                    */
/* ================================================================== */

int findDepartment(const DepartmentBudget budgets[], int count, const char *name)
{
    for (int i = 0; i < count; i++) {
        if (strcmp(budgets[i].department, name) == 0) {
            return i;
        }
    }
    return -1;
}

int addDepartmentBudget(DepartmentBudget budgets[], int count)
{
    if (count >= MAX_DEPARTMENTS) {
        printf("\n[!] Maximum number of departments (%d) reached.\n", MAX_DEPARTMENTS);
        return count;
    }

    DepartmentBudget newDept;
    memset(&newDept, 0, sizeof(newDept));

    /* ---- Validate department name ---- */
    while (1) {
        printf("\nEnter department name: ");

        if (!readLine(newDept.department, DEPT_NAME_LEN)) {
            return count;
        }

        if (strlen(newDept.department) == 0) {
            printf("[!] Department name cannot be empty.\n");
            continue;
        }

        if (findDepartment(budgets, count, newDept.department) != -1) {
            printf("[!] Department '%s' already exists.\n", newDept.department);
            continue;
        }

        break;
    }

    /* ---- Validate allocated budget ---- */
    if (!readNonNegativeDouble("Enter allocated budget (N$): ",
                               &newDept.allocatedBudget)) {
        return count;
    }

    newDept.expenditure = 0.0; /* starts at zero */

    budgets[count] = newDept;
    count++;

    printf("[OK] Department '%s' added with budget N$%.2f\n",
           newDept.department, newDept.allocatedBudget);

    return count;
}

void enterExpenditure(DepartmentBudget budgets[], int count)
{
    if (count == 0) {
        printf("\n[!] No departments registered yet. Add a budget first.\n");
        return;
    }

    char name[DEPT_NAME_LEN];
    printf("\nEnter department name: ");

    if (!readLine(name, DEPT_NAME_LEN)) {
        return;
    }

    int idx = findDepartment(budgets, count, name);
    if (idx == -1) {
        printf("[!] Department '%s' not found.\n", name);
        return;
    }

    double amount;
    if (!readNonNegativeDouble("Enter expenditure amount (N$): ", &amount)) {
        return;
    }

    budgets[idx].expenditure += amount;

    double remaining = budgets[idx].allocatedBudget - budgets[idx].expenditure;

    printf("[OK] Expenditure recorded for '%s'.\n", budgets[idx].department);
    printf("     Allocated   : N$%.2f\n", budgets[idx].allocatedBudget);
    printf("     Expenditure : N$%.2f\n", budgets[idx].expenditure);
    printf("     Remaining   : N$%.2f\n", remaining);

    if (remaining < 0.0) {
        printf("[!] WARNING: '%s' is OVER budget by N$%.2f\n",
               budgets[idx].department, -remaining);
    } else {
        printf("     Status      : WITHIN BUDGET\n");
    }
}

void displayBudgets(const DepartmentBudget budgets[], int count)
{
    if (count == 0) {
        printf("\n[!] No departments to display.\n");
        return;
    }

    printf("\n");
    printf("=====================================================================================\n");
    printf("%-20s %-15s %-15s %-15s %-15s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printf("=====================================================================================\n");

    for (int i = 0; i < count; i++) {
        double remaining = budgets[i].allocatedBudget - budgets[i].expenditure;
        const char *status = (remaining < 0.0) ? "OVER BUDGET" : "WITHIN BUDGET";

        printf("%-20s N$%-13.2f N$%-13.2f N$%-13.2f %-15s\n",
               budgets[i].department,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               remaining,
               status);
    }

    printf("=====================================================================================\n");

    printf("TOTAL ALLOCATED   : N$%.2f\n", calculateTotalAllocated(budgets, count));
    printf("TOTAL EXPENDITURE : N$%.2f\n", calculateTotalExpenditure(budgets, count));
    printf("TOTAL REMAINING   : N$%.2f\n",
           calculateTotalAllocated(budgets, count) -
           calculateTotalExpenditure(budgets, count));
}

void displayOverBudget(const DepartmentBudget budgets[], int count)
{
    int found = 0;

    printf("\n--- Departments Exceeding Budget ---\n");

    for (int i = 0; i < count; i++) {
        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            double over = budgets[i].expenditure - budgets[i].allocatedBudget;
            printf("  %-20s over by N$%.2f\n", budgets[i].department, over);
            found = 1;
        }
    }

    if (!found) {
        printf("  None. All departments are within budget.\n");
    }
}

double calculateTotalAllocated(const DepartmentBudget budgets[], int count)
{
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += budgets[i].allocatedBudget;
    }
    return total;
}

double calculateTotalExpenditure(const DepartmentBudget budgets[], int count)
{
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += budgets[i].expenditure;
    }
    return total;
}

/* ================================================================== */
/*  Budget Sub-Menu                                                    */
/* ================================================================== */

void budgetMenu(void)
{
    /* Persistent storage for the lifetime of the program run */
    static DepartmentBudget budgets[MAX_DEPARTMENTS];
    static int count = 0;

    int choice;

    do {
        printf("\n");
        printf("=========================================\n");
        printf("        BUDGET MANAGEMENT MENU\n");
        printf("=========================================\n");
        printf("  1. Add Department Budget\n");
        printf("  2. Enter Expenditure\n");
        printf("  3. Display All Budgets\n");
        printf("  4. Show Over-Budget Departments\n");
        printf("  5. Back to Main Menu\n");
        printf("=========================================\n");
        printf("Enter your choice: ");

        char line[16];
        if (!readLine(line, sizeof(line))) {
            choice = 5; /* exit on EOF */
        } else if (strlen(line) == 0) {
            choice = -1;
        } else {
            char *endPtr;
            long val = strtol(line, &endPtr, 10);
            if (*endPtr != '\0') {
                choice = -1;
            } else {
                choice = (int)val;
            }
        }

        switch (choice) {
            case 1:
                count = addDepartmentBudget(budgets, count);
                break;
            case 2:
                enterExpenditure(budgets, count);
                break;
            case 3:
                displayBudgets(budgets, count);
                break;
            case 4:
                displayOverBudget(budgets, count);
                break;
            case 5:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("[!] Invalid choice. Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);
}