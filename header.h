
#include <cstring>

#ifndef COMPANY_MANAGEMENT_HEADER_H
#define COMPANY_MANAGEMENT_HEADER_H

#endif //COMPANY_MANAGEMENT_HEADER_H
struct date{
    int day;
    int month;
    int year;
};

struct employee
{
    char name[50];
    int employeeNumber = 0;
    int wage;
    date dateOfHiring;
    date dateOfBirth;
    int exists = 0;
};


void addEmployee(employee* newEmployee){
    char name[50];
    int number, wage, year, month, day;


    printf("Name of employee(spaces are written with _):");
    scanf("%s", name);
    strcpy(newEmployee->name, name);

    printf("\nemployeeNumber:");
    scanf("%d", &number);
    newEmployee->employeeNumber = number;


    printf("\nwage:");
    scanf("%d", &wage);
    newEmployee->wage = wage;


    do {
        printf("\nYear of hiring:");
        scanf("%d", &year);
        newEmployee->dateOfHiring.year = year;
    }
    while (year > 2024 || year < 1900);


    do {
        printf("\nMonth of hiring:");
        scanf("%d", &month);
        newEmployee->dateOfHiring.month = month;
    }
    while (month < 0 || month >= 13);


    if(month == 2 && year % 4 == 0) {
        do {
            printf("\nDay of hiring:");
            scanf("%d", &day);
            newEmployee->dateOfHiring.day = day;
        } while (day <= 0 || day >= 30);
    }

    if(month == 2 && year % 4 != 0) {
        do {
            printf("\nDay of hiring:");
            scanf("%d", &day);
            newEmployee->dateOfHiring.day = day;
        } while (day <= 0 || day >= 29);
    }

    if(month % 2 == 0 && month != 2) {
        do {
            printf("\nDay of hiring:");
            scanf("%d", &day);
            newEmployee->dateOfHiring.day = day;
        } while (day <= 0 || day >= 31);
    }

    if(month % 2 != 0) {
        do {
            printf("\nDay of hiring:");
            scanf("%d", &day);
            newEmployee->dateOfHiring.day = day;
        } while (day <= 0 || day >= 30);
    }


    do {
        printf("\nYear of birth:");
        scanf("%d", &year);
        newEmployee->dateOfBirth.year = year;
    }
    while (year > 2007 || year < 1900);


    do {
        printf("\nMonth of birth:");
        scanf("%d", &month);
        newEmployee->dateOfBirth.month = month;
    }
    while (month < 0 || month >= 13);


    if(month == 2 && year % 4 == 0) {
        do {
            printf("\nDay of birth:");
            scanf("%d", &day);
            newEmployee->dateOfBirth.day = day;
        } while (day <= 0 || day >= 30);
    }

    if(month == 2 && year % 4 != 0) {
        do {
            printf("\nDay of birth:");
            scanf("%d", &day);
            newEmployee->dateOfBirth.day = day;
        } while (day <= 0 || day >= 29);
    }

    if(month % 2 == 0 && month != 2) {
        do {
            printf("\nDay of birth:");
            scanf("%d", &day);
            newEmployee->dateOfBirth.day = day;
        } while (day <= 0 || day >= 31);
    }

    if(month % 2 != 0) {
        do {
            printf("\nDay of birth:");
            scanf("%d", &day);
            newEmployee->dateOfBirth.day = day;
        } while (day <= 0 || day >= 30);
    }

    newEmployee->exists = 1;

}

void ListEmployee(employee* newEmployee){
    printf("Name: %s \n ", newEmployee->name);
    printf("date of birth: %d/%d/d \n ", newEmployee->dateOfBirth.day , newEmployee->dateOfBirth.month, newEmployee->dateOfBirth.year);
    printf("Employee number: %d \n ", newEmployee->employeeNumber);
    printf("Employee wage: %d \n", newEmployee->wage);
    printf("date of hiring: %d/%d/%d \n\n", newEmployee->dateOfHiring.day , newEmployee->dateOfHiring.month, newEmployee->dateOfHiring.year);
    printf("----------------------------------------------\n\n");
}

int makingMoreThanX (employee* newEmployee,int amount){

    int yes;
    if(newEmployee->wage > amount){
        yes = 1;
    }else yes = 0;
    return yes;
}

int wasItBornInNovember(employee* newEmployee){
    if(newEmployee->dateOfBirth.month == 11) {
        return 1;
    }else
        return 0;
}
