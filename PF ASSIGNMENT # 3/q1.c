#include <stdio.h>
#include <string.h>


typedef struct {
    int code;
    char name[50];
    char joining[11]; 
} Employee;


void assignEmployeeValues(Employee* emp) {
    printf("Enter employee code: ");
    scanf("%d", &emp->code);
    getchar(); 
    printf("Enter employee name: ");
    fgets(emp->name, 50, stdin);
    emp->name[strcspn(emp->name, "\n")] = 0; //
    printf("Enter date of joining (YYYY-MM-DD): ");
    scanf("%s", emp->joining);
}


void calculateTenure(Employee employees[], int size) {
    int currentYear, currentMonth, currentDay;
    printf("Enter the current date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &currentYear, &currentMonth, &currentDay);

    int count = 0;
    printf("\nEmployees with tenure greater than 3 years:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        int joinYear, joinMonth, joinDay;
        sscanf(employees[i].joining, "%d-%d-%d", &joinYear, &joinMonth, &joinDay);

        int tenureYears = currentYear - joinYear;
        if ((currentMonth < joinMonth) || (currentMonth == joinMonth && currentDay < joinDay)) {
            tenureYears--; 
        }

        if (tenureYears > 3) {
            count++;
            printf("Employee Code: %d\n", employees[i].code);
            printf("Employee Name: %s\n", employees[i].name);
            printf("Date of Joining: %s\n", employees[i].joining);
            printf("Tenure: %d years\n\n", tenureYears);
        }
    }

    printf("Total employees with tenure > 3 years: %d\n", count);
}

int main() {
    Employee employees[4];

    
    printf("Enter details for 4 employees:\n");
    for (int i = 0; i < 4; i++) {
        printf("\nEmployee %d:\n", i + 1);
        assignEmployeeValues(&employees[i]);
    }

    calculateTenure(employees, 4);

    return 0;
}
