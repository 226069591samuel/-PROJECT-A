#include <stdio.h>
#include <string.h>
#include "employees.h"

    //Contrusting a Array to hold the employees

        struct Employee employees[MAX]; //learn more of struct**
        int employeeCount = 0;

        void addEmployee() {
            if (employeeCount >= MAX) {
                printf("Employee list is full.\n");
                return;
            }

            printf("Enter the Employee ID: ");
            fflush(stdout);
            scanf("%d", &employees[employeeCount].id);

            printf("Enter the Employee name: ");
            fflush(stdout);
            scanf(" %49[^\n]", employees[employeeCount].name);

            printf("Enter Your Department: ");
            fflush(stdout);
            scanf(" %49[^\n]", employees[employeeCount].department);

            printf("Enter Basic Salary: ");
            fflush(stdout);
            scanf("%f", &employees[employeeCount].basicSalary);

            printf("Enter Housing Allowance: ");
            fflush(stdout);
            scanf("%f", &employees[employeeCount].housing);

            printf("Enter the Transport Allowance: ");
            fflush(stdout);
            scanf("%f", &employees[employeeCount].transport);

            employeeCount++;
            printf("Employee added.\n");

        }

    //Adding displayEmployee right below the addEmployee

        void displayEmployees() {
    //If there are no amount of employees to be displayed prints and indication
            if (employeeCount == 0) {
                printf("No employees YET!\n");
                return;
            }

            printf("\n    THE EMPLOYEE LIST    \n");

                for (int i=0; i < employeeCount; i++) {
                    printf("ID: %d\n", employees[i].id);
                    printf("Name: %s\n", employees[i].name);
                    printf("Department: %s\n", employees[i].department);
                    printf("Basic Salary: %.2f\n", employees[i].basicSalary);
                    printf("Housing Allowance: %.2f\n", employees[i].housing);
                    printf("Transport Allowance: %.2f\n", employees[i].transport);

            printf("\n---------------------YAYYYYY!-----------------------\n");
                }
        }

        void searchEmployee() {
    //Here a user must be able to search and find an employee
         int searchId;
         int found = 0;
         char again;
    /*if employee not found, the system should be able to bring them back to the
        start of the prompt... */

        do { // Lets add a do..while - to let the system run at least once then again only if user says 'yes'

             found = 0; //Every new search needs a fresh start.

        printf("Enter employee ID to search: \n");
        fflush(stdout);
        scanf("%d", &searchId);

        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].id == searchId) {
                printf("THE EMPLOYEE IS FOUND! \n");
                printf("ID: %d\n", employees[i].id);
                printf("Name: %s\n", employees[i].name);
                printf("Department: %s\n", employees[i].department);
                printf("Basic Salary: %.2f\n", employees[i].basicSalary);
                printf("Housing Allowance: %.2f\n", employees[i].housing);
                printf("Transport Allowance: %.2f\n", employees[i].transport);
                found = 1;
                break;
            }
        }

        if (found == 0) {
            printf("Employee Can't Be Found!\n"); //Try again sweetie...:)
            printf("TRY AGAIN! (y/n): ");
            fflush(stdout);
            scanf(" %c", &again);
        } else {
            again = 'n';/*if the employee was found, i dont need the loop to run forever
                          setting this will allow the while (false) so the loop ends*/
        }

    } while (again == 'y');
}

        void calculateSalary() {
    //Here Calacute & Display gross income of the employee
            int searchId;
            int found = 0;
            float gross;

            printf("Enter ID to calculate the salary: ");
            fflush(stdout);
            scanf("%d", &searchId);

            for (int i = 0; i < employeeCount; i++) {
                if (employees[i].id == searchId){
                    gross = employees[i].basicSalary + employees[i].housing + employees[i].transport;

                printf("-------Salary INFO-----\n");
                printf("Employee: %s\n", employees[i].name);
                printf("Basic Salary: %.2f\n", employees[i].basicSalary);
                printf("Housing Allowance: %.2f\n", employees[i].housing);
                printf("Transport Allowance: %.2f\n", employees[i].transport);
                printf("Gross Income: %.2f\n", gross);

                found = 1;
                break;
            }
            }

            if (found == 0) {
                printf("Employee with ID %d not found. \n", searchId);
            }
        }
