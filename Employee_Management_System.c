#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee* next;
} Employee;

Employee* head = NULL;

// Function to check if ID already exists
int id_exists(int id) {
    Employee* temp = head;
    while (temp) {
        if (temp->id == id)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// Add Employee
void add_employee() {
    Employee* new_emp = (Employee*)malloc(sizeof(Employee));
    printf("Enter Employee ID: ");
    scanf("%d", &new_emp->id);
    
    if (id_exists(new_emp->id)) {
        printf("Employee ID already exists!\n");
        free(new_emp);
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]s", new_emp->name);
    printf("Enter Salary: ");
    scanf("%f", &new_emp->salary);
    
    new_emp->next = head;
    head = new_emp;

    printf("Employee added successfully!\n");
}

// Display all Employees
void display_employees() {
    if (!head) {
        printf("No employee records found.\n");
        return;
    }
    Employee* temp = head;
    printf("\n--- Employee List ---\n");
    while (temp) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", temp->id, temp->name, temp->salary);
        temp = temp->next;
    }
}

// Update Employee
void update_employee() {
    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);
    
    Employee* temp = head;
    while (temp) {
        if (temp->id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]s", temp->name);
            printf("Enter New Salary: ");
            scanf("%f", &temp->salary);
            printf("Record updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Employee not found.\n");
}

// Delete Employee
void delete_employee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    
    Employee *temp = head, *prev = NULL;

    while (temp) {
        if (temp->id == id) {
            if (prev)
                prev->next = temp->next;
            else
                head = temp->next;
            free(temp);
            printf("Employee deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Employee not found.\n");
}

// Menu
void menu() {
    int choice;
    while (1) {
        printf("\n===== Employee Management Menu =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_employee(); break;
            case 2: display_employees(); break;
            case 3: update_employee(); break;
            case 4: delete_employee(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
