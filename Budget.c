#include <stdio.h>
int main(){
char department [10][50];
double allocatedBudget [10], totalExpenditure [10], remainingBudget [10];
int numberOfDepartments;

printf("Enter number of departments(Maximum 10):\n");
    scanf("%d", &numberOfDepartments);

    while(numberOfDepartments<1 || numberOfDepartments>10){
        printf("Invalid number of departments. Enter a number between 1 and 10:\n");
        scanf("%d", &numberOfDepartments);
    }        
    
for (int i = 0; i < numberOfDepartments; i++) {

    printf("\nEnter department:\n");
    scanf(" %49[^\n]", department[i]);

    printf("Enter allocatedBudget:\n ");
    scanf("%lf", &allocatedBudget[i]);

    while (allocatedBudget[i] < 1000){
        printf("Budget cannot be less than 1000. Re-enter budget:\n");
        scanf("%lf", &allocatedBudget[i]);
    }

    printf("Enter totalExpenditure:\n");
    scanf("%lf", &totalExpenditure[i]);

    while (totalExpenditure[i] < 0) {
        printf("Total expenditure cannot be negative. Re-enter Expenditure:\n");
        scanf("%lf", &totalExpenditure[i]);
    }

    remainingBudget[i] = allocatedBudget[i] - totalExpenditure[i];  // calculate FIRST

    printf("\n\n---Department Budget Report---\n");
    printf("Department: %s\n", department[i]);
    printf("AllocatedBudget: %.2f\n", allocatedBudget[i]);
    printf("TotalExpenditure: %.2f\n", totalExpenditure[i]);
    printf("RemainingBudget: %.2f\n", remainingBudget[i]);  // then print

    if(allocatedBudget[i] > totalExpenditure[i]){
        printf(" Status: Within Budget \n");
    } else {
        printf("Status: Budget Exceeded\n");
    }
}