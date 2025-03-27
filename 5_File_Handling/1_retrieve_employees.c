#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "employees.txt"

void retrieveEmployees() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error opening file! Make sure you have stored employee data first.\n");
        return;
    }

    char email[100];
    int age;
    float salary;

    printf("\nEmployee Records:\n");
    while (fscanf(file, "%[^,], %d, %f\n", email, &age, &salary) != EOF) {
        printf("Email: %s, Age: %d, Salary: %.2f\n", email, age, salary);
    }

    fclose(file);
}

int main() {
    retrieveEmployees();
    return 0;
}

