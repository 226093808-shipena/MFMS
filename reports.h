#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

/* Part 8 - Reports */
void displayEmployeeReport(const Employee employees[], int employeeCount);
void displayBudgetReport(const DepartmentBudget budgets[], int budgetCount);
void displaySupplierReport(const Supplier suppliers[], int supplierCount);
void displayAssetReport(const Asset assets[], int assetCount);
void displayAllReports(const Employee employees[], int employeeCount,
                       const DepartmentBudget budgets[], int budgetCount,
                       const Supplier suppliers[], int supplierCount,
                       const Asset assets[], int assetCount);
void reportsMenu(void);
#endif
