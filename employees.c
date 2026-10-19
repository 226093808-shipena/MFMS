#include <stdio.h>
#include <string.h>
#include "employees.h"

#define MAX_EMPLOYEES 100
int employeeCount = 0;
Employee employees[MAX_EMPLOYEES];

int findEmployeeByID(int employeeID)
{
    int i;
    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == employeeID)
        {
            return i;
        }
    }
        return -1;
}
        float getTotalSalary(Employee employee)
    {
        return employee.basicSalary
              + employee.housingAllowance
              + employee.transportAllowance;
    }
    void addEmployee(void)
    {
        Employee newEmployee;
        printf("\n========== ADD EMPLOYEE ==========\n");
        if (employeeCount >= MAX_EMPLOYEES)
        {
            printf("Employee storage is full.\n");
            return;
        }
        printf("Enter Employee ID: ");
        if (scanf("%", &newEmployee.employeeID) != 1)
        {
            printf("Invalid ID. Please enter a number.\n");
            while (getchar() != '\n');
            return;
        }
        if (newEmployee.employeeID <= 0)
        {
            printf("Employee ID must be positive.\n");
            return;
        }
        if (findEmployeeByID(newEmployee.employeeID) != -1)
        {
            printf("This Employee ID already exists.\n");
            return;
        }
        printf("Enter Employee Name: ");
    if (scanf(" %49[^\n]", newEmployee.name) != 1)
    {
        printf("Invalid employee name.\n");
        return;
    }
    if (strlen(newEmployee.name) == 0)
    {
        printf("Name cannot be empty.\n");
        return;
    }
    printf("Enter Department: \n");
        if (scanf(" %49[^\n]", newEmployee.department) != 1)
        {
        printf("Invalid department.\n");
        return;
    }
        printf("Enter Basic Salary (N$): ");
        if (scanf("%f", &newEmployee.basicSalary) != 1
        || newEmployee.basicSalary < 0)
        {
        printf("Invalid basic salary.\n");
        while (getchar() != '\n');
        return;
    }
        printf("Enter Housing Allowance (N$): ");
        if (scanf("%f", &newEmployee.housingAllowance) != 1
        || newEmployee.housingAllowance < 0)
        {
        printf("Invalid housing allowance.\n");
        while (getchar() != '\n');
        return;
    }
        printf("Enter Transport Allowance (N$): ");
        if (scanf("%f", &newEmployee.transportAllowance) != 1
        || newEmployee.transportAllowance < 0)
        {
        printf("Invalid transport allowance.\n");
        while (getchar() != '\n');
        return;
    }
        employees[employeeCount] = newEmployee;
        employeeCount++;
        printf("\nEmployee added successfully.\n");
    }
        void displayEmployees(void)
        {
        int i;
        printf("\n========== EMPLOYEE REGISTER ==========\n");
        if (employeeCount == 0)
        {
        printf("No employee have been registered.\n");
        return;
    }
        for (i + 0; i < employeeCount; i++)
        {
        printf("\nEmployee Number: %d\n", i + 1);
        printf("---------------------------------------\n");
        printf("Employee ID          : %d\n", employees[i].employeeID);
        printf("Name                 : %s\n", employees[i].name);
        printf("Department            :%s\n", employees[i].department);
        printf("Basic Salary          :N$%.2f\n", employees[i].basicSalary);
        printf("Housing Allowance    : N$%.2f\n",employees[i].housingAllowance);
        printf("Transport Allowance : N$%.2f\n", employees[i].transportAllowance);
        printf("Total Salary       : N$%.2f\n", getTotalSalary(employees[i]));
    }
        printf("\nTotal Registered Employees: %d\n", employeeCount);
    }
        void searchEmployee(void)
        {
        int choice;
        int employeeID;
        int index;
        int found = 0;
        char searchName[50];
        if (employeeCount == 0)
        {
        printf("\nNo employees available to search.\n");
        return;
    }
        printf("\n========== SEARCH EMPLOYEE ==========\n");
        printf("1. Search by Employee ID\n");
        printf("2. Search by Employee Name\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid search choice.\n");
            while (getchar() != '\n');
            return;
        }
    switch (choice)
    {
    case 1:
        printf("Enter Employee ID: ");
        if (scanf("%d", &employeeID) != 1)
        {
            printf("Invalid employee ID.\n");
            while (getchar() != '\n');
            return;
        }
        index = findEmployeeByID(employeeID);
        if (index != -1)
        {
            printf("\nEmployee not found:\n");
            printf("---------------------------------------\n");
            printf("Employee ID          : %d\n", employees[index].employeeID);
            printf("Name                 : %s\n", employees[index].name);
            printf("Department            :%s\n", employees[index].department);
            printf("Basic Salary          :N$%.2f\n", employees[index].basicSalary);
            printf("Housing Allowance    : N$%.2f\n",employees[index].housingAllowance);
            printf("Transport Allowance : N$%.2f\n", employees[index].transportAllowance);
            printf("Total Salary       : N$%.2f\n", getTotalSalary(employees[index]));
        
        }
        break;
    case 2:
        printf("Enter Employee Name: ");
        if (scanf(" %49[^\n]", searchName) != 1);
        {
            printf("Invalid  name.\n");
            return;
    }
            for (int i = 0; i < employeeCount; i++)
            {
            if (strcmp(employees[i].name, searchName) == 0)
            {
            printf("Employee found:\n");
            printf("ID: %d\n", employees[i].employeeID);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
            printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
            printf("Total Salary: N$%.2f\n", getTotalSalary(employees[i]));
            found = 1;
    }
    }
    if (!found)
    {
    printf("Employee not found.\n");
    }
    break;
    default:
    printf("Invalid search option. Choose 1 or 2.\n");
    }
    }
    void calculateSalary(void)
    {
    int employeeID;
    int index;
    if (employeeCount == 0)
    {
    printf("\nNo employees available.\n");
    return;
    }
    printf("\n========== SALARY CALCULATION ==========\n");
    printf("Enter Employee ID: ");
    if (scanf("%d", &employeeID) != 1)
    {
    printf("Invalid ID.\n");
    while (getchar() != '\n');
    return;
    }
    index = findEmployeeByID(employeeID);
    if (index == -1)
    {
    printf("Employee not found.\n");
    return;
    }
    printf("\nEmployee: %s\n", employees[index].name);
    printf("Basic Salary : M%.2f\n", employees[index].basicSalary);
    printf("Housing Allowance : M%.2f\n", employees[index].housingAllowance);
    printf("Transport Allowance  :M%.2f\n", employees[index].transportAllowance);
    printf("Total Salary : M%.2f\n", getTotalSalary(employees[index]));
    }
    void employeeMenu(void)
    {
    int choice;
    do
    {
    printf("\n====================\n");
    printf("         EMPLOYEE MANAGEMENT\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Search Employee\n");
    printf("4. Calculate Salary\n");
    printf("5. Return to Main Menu\n");
    printf("======================\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid choice. Please enter a number.\n");
        while (getchar() != '\n');
        continue;
    }
    switch(choice){
    
        case 1:
            addEmployee();
            break;
        
        case 2:
            displayEmployees();
                break;
        case 3:
                searchEmployee();
                break;
        case 4:
                calculateSalary();
                break;
        case 5:
                printf("Returning to the main menu.\n");
                break;
        default:
                printf("Invalid choice. Please enter a number.\n");
                break;
        }
    } while (choice != 5);
}