#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Employee.csv"
#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

void loadEmployees() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return;

    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), file) == NULL && !feof(file)) {
        fclose(file);
        return; 
    }


    while (fscanf(file, "%d,%49[^,],%49[^,],%f\n", &employees[numEmployees].id, employees[numEmployees].name, employees[numEmployees].department, &employees[numEmployees].salary) == 4) {
        numEmployees++;
        if (numEmployees >= MAX_EMPLOYEES) break;
    }
    fclose(file);
}

void saveEmployees() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Error saving file");
        return;
    }
    fprintf(file, "ID,Name,Department,Salary\n");
    for (int i = 0; i < numEmployees; i++) {
        fprintf(file, "%d,%s,%s,%.2f\n", employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
    fclose(file);
}

void addEmployee() {
    if (numEmployees >= MAX_EMPLOYEES) {
        printf("\nMaximum employees reached.\n");
        return;
    }
    printf("\n--- Add New Employee ---\n");
    int newId;
    printf("ID: ");
    if (scanf("%d", &newId) != 1) {
        printf("Invalid input for ID. Please enter a number.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == newId) {
            printf("Error: Employee ID %d already exists.\n", newId);
            return;
        }
    }
    employees[numEmployees].id = newId;

    printf("Name: ");
    scanf(" %49[^\n]", employees[numEmployees].name);
    while (getchar() != '\n');

    printf("Department: ");
    scanf(" %49[^\n]", employees[numEmployees].department);
    while (getchar() != '\n');

    printf("Salary: ");
    if (scanf("%f", &employees[numEmployees].salary) != 1) {
        printf("Invalid input for Salary. Please enter a number.\n");
        while (getchar() != '\n'); 
        return;
    }
    while (getchar() != '\n');

    numEmployees++;
    saveEmployees();
    printf("\nEmployee added successfully!\n");
}

void listEmployees() {
    if (numEmployees == 0) {
        printf("\n--- Employee List ---\n");
        printf("No employees to display.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    printf("%-5s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%-5d %-20s %-20s %-10.2f\n", employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
}

void updateEmployee() {
    int idToUpdate;
    printf("\n--- Update Employee ---\n");
    printf("Enter the ID of the employee to update: ");
    if (scanf("%d", &idToUpdate) != 1) {
        printf("Invalid input for ID. Please enter a number.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    int foundIndex = -1;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == idToUpdate) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("\nEmployee with ID %d not found.\n", idToUpdate);
        return;
    }

    printf("\nFound Employee:\n");
    printf("ID: %d, Name: %s, Department: %s, Salary: %.2f\n",
           employees[foundIndex].id, employees[foundIndex].name, employees[foundIndex].department, employees[foundIndex].salary);

    printf("\n--- Enter New Details (Leave blank or specific value to keep current) ---\n");
    char newName[MAX_NAME_LENGTH];
    char newDepartment[MAX_DEPARTMENT_LENGTH];
    float newSalaryFloat;
    int newId;

    printf("New ID (Enter 0 to keep %d): ", employees[foundIndex].id);
    if (scanf("%d", &newId) != 1) {
        printf("Invalid input for new ID.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (newId != 0 && newId != employees[foundIndex].id) {
        int idExists = 0;
        for (int i = 0; i < numEmployees; i++) {
            if (i != foundIndex && employees[i].id == newId) {
                idExists = 1;
                break;
            }
        }
        if (idExists) {
            printf("Error: Employee ID %d already exists.\n", newId);
            return;
        }
        employees[foundIndex].id = newId;
    }

    printf("New Name (Enter '.' to keep '%s'): ", employees[foundIndex].name);
    scanf(" %49[^\n]", newName);
    while (getchar() != '\n');
    if (strcmp(newName, ".") != 0) {
        strcpy(employees[foundIndex].name, newName);
    }

    printf("New Department (Enter '.' to keep '%s'): ", employees[foundIndex].department);
    scanf(" %49[^\n]", newDepartment);
    while (getchar() != '\n');
    if (strcmp(newDepartment, ".") != 0) {
        strcpy(employees[foundIndex].department, newDepartment);
    }

    printf("New Salary (Enter -1 to keep %.2f): ", employees[foundIndex].salary);
    if (scanf("%f", &newSalaryFloat) != 1) {
        printf("Invalid input for new salary.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');
    if (newSalaryFloat != -1) {
        employees[foundIndex].salary = newSalaryFloat;
    }

    saveEmployees();
    printf("\nEmployee with old ID %d updated successfully!\n", idToUpdate);
}

void searchEmployee() {
    int searchId;
    printf("\n--- Search Employee ---\n");
    printf("Enter the ID of the employee to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid input for ID. Please enter a number.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    int foundIndex = -1;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == searchId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("\n--- Employee Found ---\n");
        printf("%-5s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
        printf("----------------------------------------------------------\n");
        printf("%-5d %-20s %-20s %-10.2f\n", employees[foundIndex].id, employees[foundIndex].name, employees[foundIndex].department, employees[foundIndex].salary);
    } else {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
}

void deleteEmployee() {
    int idToDelete;
    printf("\n--- Delete Employee ---\n");
    printf("Enter the ID of the employee to delete: ");
    if (scanf("%d", &idToDelete) != 1) {
        printf("Invalid input for ID. Please enter a number.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    int foundIndex = -1;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == idToDelete) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("\nEmployee with ID %d not found.\n", idToDelete);
        return;
    }

    for (int i = foundIndex; i < numEmployees - 1; i++) {
        employees[i] = employees[i + 1];
    }
    numEmployees--;
    saveEmployees();
    printf("\nEmployee with ID %d deleted successfully!\n", idToDelete);
}

void manipulateSalary() {
    int idToManipulate;
    printf("\n--- Manipulate Employee Salary ---\n");
    printf("Enter the ID of the employee: ");
    if (scanf("%d", &idToManipulate) != 1) {
        printf("Invalid input for ID. Please enter a number.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    int foundIndex = -1;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == idToManipulate) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("\nEmployee with ID %d not found.\n", idToManipulate);
        return;
    }

    printf("\nFound Employee: ID: %d, Name: %s, Current Salary: %.2f\n",
           employees[foundIndex].id, employees[foundIndex].name, employees[foundIndex].salary);

    int choice;
    float amount;

    printf("1. Add to salary\n");
    printf("2. Subtract from salary\n");
    printf("Enter your choice (1 or 2): ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid choice input.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (choice != 1 && choice != 2) {
        printf("Invalid choice. Please enter 1 to add or 2 to subtract.\n");
        return;
    }

    printf("Enter the amount: ");
    if (scanf("%f", &amount) != 1) {
        printf("Invalid amount input.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (amount < 0) {
        printf("Amount cannot be negative. For subtraction, choose the subtract option.\n");
        return;
    }

    if (choice == 1) {
        employees[foundIndex].salary += amount;
        printf("Salary updated. New salary: %.2f\n", employees[foundIndex].salary);
    } else {
        if (employees[foundIndex].salary >= amount) {
            employees[foundIndex].salary -= amount;
            printf("Salary updated. New salary: %.2f\n", employees[foundIndex].salary);
        } else {
            printf("Error: Subtraction amount (%.2f) is greater than current salary (%.2f).\n", amount, employees[foundIndex].salary);
            printf("Salary not changed.\n");
            return; 
        }
    }

    saveEmployees();
    printf("Salary manipulation for employee ID %d processed successfully!\n", idToManipulate);
}


int main() {
    loadEmployees();

    int choice;
    while (1) {
        printf("\n--- Employee Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Update Employee\n");
        printf("4. Search Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Manipulate Salary\n"); 
        printf("7. Exit\n");             
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number between 1 and 7.\n");
            while (getchar() != '\n');
            continue; 
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                listEmployees();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                manipulateSalary();
                break;
            case 7:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
