#ifndef REPORTS_H
#define REPORTS_H

#define MAX_EMPLOYEES 100
#define MAX_BUDGETS 50
#define MAX_SUPPLIERS 100
#define MAX_ASSETS 100

typedef struct {
    int employeeID;
    char name[100];
    char department[50];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double otherAllowance;
} Employee;

typedef struct {
    char department[50];
    double allocatedBudget;
    double expenditure;
} Budget;

typedef struct {
    int supplierID;
    char name[100];
    char email[100];
    char telephone[30];
    char town[50];
} Supplier;

typedef struct {
    int assetID;
    char name[100];
    char type[50];
    double purchaseValue;
    char department[50];
    char condition[50];
} Asset;

/* Part 8 - Reports */
void displayEmployeeReport(const Employee employees[], int employeeCount);
void displayBudgetReport(const Budget budgets[], int budgetCount);
void displaySupplierReport(const Supplier suppliers[], int supplierCount);
void displayAssetReport(const Asset assets[], int assetCount);
void displayAllReports(const Employee employees[], int employeeCount,
                       const Budget budgets[], int budgetCount,
                       const Supplier suppliers[], int supplierCount,
                       const Asset assets[], int assetCount);

#endif
