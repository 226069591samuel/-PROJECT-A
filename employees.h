#ifndef EMPLOYEES_H 
#define EMPLOYEES_H

#define MAX 100 

struct Employee {

    int id;
    char name[50];
    char department[50];
    float basicSalary;
    float housing;
    float transport;

};

    void addEmployee();
    void displayEmployees();
    void searchEmployee();
    void calculateSalary();

    #endif
