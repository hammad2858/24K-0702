#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

   
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Roll No: \n");
        scanf("%d", &students[i].roll_no);

        printf("Name: \n");
        scanf("%s", students[i].name);

        printf("Marks: \n");
        scanf("%f", &students[i].marks);
    }

    
    float total_marks = 0.0;
    for (int i = 0; i < n; i++) {
        total_marks += students[i].marks;
    }
    float average_marks = total_marks / n;

    
    printf("\nAverage marks of the class: %.2f\n", average_marks);

    
    free(students);

    return 0;
}