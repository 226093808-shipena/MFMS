#ifndef EMPLOYEES_H
#define EMPLOYEES_H

typedef struct {
    int employeeID;
    char name[50];
    char department[50];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double otherAllowance;
} Employee;

void addEmployee(Employee employees[], int *employeeCount);
void displayEmployees(const Employee employees[], int employeeCount);

#endif