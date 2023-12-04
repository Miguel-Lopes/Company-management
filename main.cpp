#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void addEmployee(employee* newEmployee);
void ListEmployee(employee* newEmployee);
int makingMoreThanX (employee* newEmployee,int amount);
int wasItBornInNovember(employee* newEmployee);


int main() {
   struct employee allEmployees[50] ;
   int i;
   int chosenEmployeeNumber;
   int counter = 0;
   int choice = 0;
   int numberOfEmployees = 0;
   float result;
   float amount = 0;
   float averageWage = 0;
   float costOfLabour = 0;
   int bornInNovember = 0;

   start:

    printf("-----------------WELCOME TO THE COOL COMPANY-----------------\n\n");
    printf("Number of employees:%d          average wage:%.2f          employees born in november:%d \n\n", numberOfEmployees, averageWage, bornInNovember);
    printf("Which of the following operations would you like to do? \n 1->Add employee \n 2->List employees \n 3->Show data of specific employee \n 4-> Percentage of employees that make more money than x \n\n");

    scanf("%d", &choice);

    do {
        switch (choice) {
            case 1:
                for (i = 0; i < 50; i++) {
                    if (allEmployees[i].exists == 0) {
                        addEmployee(&allEmployees[i]);
                        printf("\nEmployee successfully added to position %d\n\n", i);
                        numberOfEmployees++;
                        costOfLabour =  costOfLabour + allEmployees[i].wage;
                        averageWage = costOfLabour / numberOfEmployees;
                        bornInNovember = wasItBornInNovember(&allEmployees[i]);
                        goto start;
                        }
                    }
                break;
            case 2:
                for (i = 0; i < 50; i++) {
                    if (allEmployees[i].exists != 0) {
                        ListEmployee(&allEmployees[i]);
                        } else if (allEmployees[0].exists == 0) {
                        printf("We cant detect any employees \n");
                        goto start;
                    }
                        else{printf("We cant detect any more employees \n");
                        goto start;}
                    }
                break;
            case 3:
                printf("Number of the employee:");
                scanf("%d", &chosenEmployeeNumber);

                for (i = 0; i < 50; i++) {
                    if (allEmployees[i].employeeNumber == chosenEmployeeNumber) {
                        ListEmployee(&allEmployees[i]);
                        goto start;
                    }
                    else if (i == 49) {
                        printf("No one exists with that number");
                        }
                }
                break;
            case 4:

                printf("Whats the amount you want to ask:");
                scanf("%f", &amount);

                for (i = 0; i < 50; i++) {
                    if (allEmployees[i].exists != 0) {
                        counter = counter + makingMoreThanX(&allEmployees[i], amount);
                        }
                }
                result =  (counter / (float)numberOfEmployees) * 100;
                printf("The percentange of employees making more than %.2f is %.2f \n\n", amount, result);
                goto start;

                default:
                printf("You may only pick one of the available choices");
                break;
        }
    } while (choice > 0 && choice < 6 );


    return 0;
}