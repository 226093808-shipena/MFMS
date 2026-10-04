/**
 * @file    budget.h
 * @brief   Budget Management module for the Municipal Financial Management System (MFMS).
 * @course  PAP521S - Programming in Practice
 * @project Project A - Foundation System
 *
 * This module handles departmental budget allocation, expenditure tracking,
 * balance calculation, and over-budget reporting.
 */

#ifndef BUDGET_H
#define BUDGET_H

/* ------------------------------------------------------------------ */
/*  Constants                                                          */
/* ------------------------------------------------------------------ */
#define MAX_DEPARTMENTS 20
#define DEPT_NAME_LEN   50

/* ------------------------------------------------------------------ */
/*  Data Structures                                                    */
/* ------------------------------------------------------------------ */

/**
 * @struct DepartmentBudget
 * @brief  Represents a single department's allocated budget and spending.
 */
typedef struct {
    char   department[DEPT_NAME_LEN]; /**< Department name (e.g., "Finance") */
    double allocatedBudget;           /**< Total allocated budget (N$)      */
    double expenditure;               /**< Total money spent so far (N$)    */
} DepartmentBudget;

/* ------------------------------------------------------------------ */
/*  Public Function Prototypes                                         */
/* ------------------------------------------------------------------ */

/**
 * @brief  Displays the Budget Management sub-menu and handles user input.
 *         This is the entry point called from the main menu.
 */
void budgetMenu(void);

/**
 * @brief  Adds a new department with an allocated budget.
 * @param  budgets  Array of department budgets.
 * @param  count    Current number of departments in the array.
 * @return Updated count of departments.
 */
int addDepartmentBudget(DepartmentBudget budgets[], int count);

/**
 * @brief  Records an expenditure for an existing department.
 * @param  budgets  Array of department budgets.
 * @param  count    Current number of departments.
 */
void enterExpenditure(DepartmentBudget budgets[], int count);

/**
 * @brief  Displays all departments with budgets, expenditure, remaining, and status.
 * @param  budgets  Array of department budgets.
 * @param  count    Current number of departments.
 */
void displayBudgets(const DepartmentBudget budgets[], int count);

/**
 * @brief  Lists all departments whose expenditure exceeds their allocated budget.
 * @param  budgets  Array of department budgets.
 * @param  count    Current number of departments.
 */
void displayOverBudget(const DepartmentBudget budgets[], int count);

/**
 * @brief  Finds the index of a department by name (case-sensitive).
 * @param  budgets  Array of department budgets.
 * @param  count    Current number of departments.
 * @param  name     Department name to search for.
 * @return Index if found, otherwise -1.
 */
int findDepartment(const DepartmentBudget budgets[], int count, const char *name);

/**
 * @brief  Calculates the total allocated budget across all departments.
 * @param  budgets  Array of department budgets.
 * @param  count    Current number of departments.
 * @return Sum of all allocated budgets.
 */
double calculateTotalAllocated(const DepartmentBudget budgets[], int count);

/**
 * @brief  Calculates the total expenditure across all departments.
 * @param  budgets  Array of department budgets.
 * @param  count    Current number of departments.
 * @return Sum of all expenditures.
 */
double calculateTotalExpenditure(const DepartmentBudget budgets[], int count);

#endif /* BUDGET_H */