#include <stdio.h>
#include <string.h>
#include "reports.h"

static double calculateEmployeeSalary(const Employee *employee)
{
    return employee->basicSalary
         + employee->housingAllowance
         + employee->transportAllowance
         + employee->otherAllowance;
}

void displayEmployeeReport(const Employee employees[], int employeeCount)
{
    int i;
    double totalSalary = 0.0;
    double highestSalary = 0.0;
    double lowestSalary = 0.0;

    printf("\n========================================\n");
    printf("           EMPLOYEE REPORT\n");
    printf("========================================\n");

    if (employeeCount <= 0) {
        printf("No employees are currently registered.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++) {
        double salary = calculateEmployeeSalary(&employees[i]);
        totalSalary += salary;

        if (i == 0 || salary > highestSalary)
            highestSalary = salary;

        if (i == 0 || salary < lowestSalary)
            lowestSalary = salary;
    }

    printf("Total Employees : %d\n", employeeCount);
    printf("Average Salary  : N$%.2f\n", totalSalary / employeeCount);
    printf("Highest Salary  : N$%.2f\n", highestSalary);
    printf("Lowest Salary   : N$%.2f\n", lowestSalary);

    printf("\nEmployee Details:\n");
    printf("%-8s %-24s %-18s %-14s\n",
           "ID", "Name", "Department", "Salary");
    printf("---------------------------------------------------------------------\n");

    for (i = 0; i < employeeCount; i++) {
        printf("%-8d %-24s %-18s N$%-12.2f\n",
               employees[i].employeeID,
               employees[i].name,
               employees[i].department,
               calculateEmployeeSalary(&employees[i]));
    }
}

void displayBudgetReport(const Budget budgets[], int budgetCount)
{
    int i;
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    double remaining;

    printf("\n========================================\n");
    printf("             BUDGET REPORT\n");
    printf("========================================\n");

    if (budgetCount <= 0) {
        printf("No departmental budgets are currently registered.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    remaining = totalAllocated - totalExpenditure;

    printf("Total Allocated Budget : N$%.2f\n", totalAllocated);
    printf("Total Expenditure      : N$%.2f\n", totalExpenditure);
    printf("Remaining Budget       : N$%.2f\n", remaining);

    printf("\nDepartment Details:\n");
    printf("%-20s %-18s %-18s %-18s\n",
           "Department", "Allocated", "Expenditure", "Status");
    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < budgetCount; i++) {
        const char *status =
            (budgets[i].expenditure > budgets[i].allocatedBudget)
            ? "EXCEEDED BUDGET"
            : "WITHIN BUDGET";

        printf("%-20s N$%-16.2f N$%-16.2f %s\n",
               budgets[i].department,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               status);
    }

    printf("\nDepartments exceeding budget:\n");
    {
        int found = 0;
        for (i = 0; i < budgetCount; i++) {
            if (budgets[i].expenditure > budgets[i].allocatedBudget) {
                printf("- %s (Over by N$%.2f)\n",
                       budgets[i].department,
                       budgets[i].expenditure - budgets[i].allocatedBudget);
                found = 1;
            }
        }
        if (!found)
            printf("None.\n");
    }
}

void displaySupplierReport(const Supplier suppliers[], int supplierCount)
{
    int i;

    printf("\n========================================\n");
    printf("            SUPPLIER REPORT\n");
    printf("========================================\n");

    if (supplierCount <= 0) {
        printf("No suppliers are currently registered.\n");
        return;
    }

    printf("%-8s %-24s %-30s %-16s %-18s\n",
           "ID", "Supplier Name", "Email", "Telephone", "Town/Location");
    printf("------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < supplierCount; i++) {
        printf("%-8d %-24s %-30s %-16s %-18s\n",
               suppliers[i].supplierID,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].telephone,
               suppliers[i].town);
    }

    printf("\nTotal Suppliers: %d\n", supplierCount);
}

void displayAssetReport(const Asset assets[], int assetCount)
{
    int i;
    double totalValue = 0.0;

    printf("\n========================================\n");
    printf("              ASSET REPORT\n");
    printf("========================================\n");

    if (assetCount <= 0) {
        printf("No municipal assets are currently registered.\n");
        return;
    }

    printf("%-8s %-22s %-16s %-16s %-18s %-15s\n",
           "ID", "Asset Name", "Type", "Purchase Value",
           "Department", "Condition");
    printf("----------------------------------------------------------------------------------------------\n");

    for (i = 0; i < assetCount; i++) {
        totalValue += assets[i].purchaseValue;
        printf("%-8d %-22s %-16s N$%-14.2f %-18s %-15s\n",
               assets[i].assetID,
               assets[i].name,
               assets[i].type,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
    }

    printf("\nTotal Registered Assets: %d\n", assetCount);
    printf("Total Purchase Value   : N$%.2f\n", totalValue);
}

void displayAllReports(const Employee employees[], int employeeCount,
                       const Budget budgets[], int budgetCount,
                       const Supplier suppliers[], int supplierCount,
                       const Asset assets[], int assetCount)
{
    displayEmployeeReport(employees, employeeCount);
    displayBudgetReport(budgets, budgetCount);
    displaySupplierReport(suppliers, supplierCount);
    displayAssetReport(assets, assetCount);
}
