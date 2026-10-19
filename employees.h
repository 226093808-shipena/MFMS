#define MAX_EMPLOYEES 100
#ifndef EMPLOYEES_H
#define EMPLOYEES_H

typedef struct {
    int employeeID;
    char name[50];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    float otherAllowance;
} Employee;
void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);

int findEmployeeByID(int employeeID);
float getTotalSalary(Employee employee);

#endif