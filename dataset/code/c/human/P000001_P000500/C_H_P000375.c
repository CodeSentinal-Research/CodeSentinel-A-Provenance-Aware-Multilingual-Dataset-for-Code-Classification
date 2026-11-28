#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[100];
    int age;
    char disease[100];
    float charges;
    struct Patient* next;
};

struct Patient* head = NULL;

// Load data from file
void loadFromFile() {
    FILE* file = fopen("patient.txt", "r");
    if (file == NULL) return;

    struct Patient temp;
    struct Patient* last = NULL;
    head = NULL;

    while (fscanf(file, "%d \"%[^\"]\" %d \"%[^\"]\" %f\n",
        &temp.id, temp.name, &temp.age, temp.disease, &temp.charges) == 5) {
        
        struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));
        *newNode = temp;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            last->next = newNode;
        last = newNode;
    }

    fclose(file);
}

// Save data to file
void saveToFile() {
    FILE* file = fopen("patient.txt", "w");
    if (file == NULL) return;

    struct Patient* temp = head;
    while (temp != NULL) {
        fprintf(file, "%d \"%s\" %d \"%s\" %.2f\n",
                temp->id, temp->name, temp->age, temp->disease, temp->charges);
        temp = temp->next;
    }

    fclose(file);
}

// Add new patient
void addPatient() {
    loadFromFile();
    struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));
    newNode->next = NULL;

    printf("Enter ID: ");
    scanf("%d", &newNode->id);
    getchar();

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Age: ");
    scanf("%d", &newNode->age);
    getchar();

    printf("Enter Disease: ");
    scanf(" %[^\n]", newNode->disease);

    printf("Enter Charges: ");
    scanf("%f", &newNode->charges);

    if (head == NULL)
        head = newNode;
    else {
        struct Patient* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    saveToFile();
    printf("Patient added successfully.\n");
}

// View all patients 
void viewPatients() {
    loadFromFile();
    if (head == NULL) {
        printf("No patient records found.\n");
        return;
    }

    printf("\n---Patient Records--- ");

    // Sorting by ID 
    struct Patient *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->id > j->id) {
                // Swapping all fields
                int tempId = i->id;
                i->id = j->id;
                j->id = tempId;

                int tempAge = i->age;
                i->age = j->age;
                j->age = tempAge;

                float tempCharges = i->charges;
                i->charges = j->charges;
                j->charges = tempCharges;

                char tempName[100], tempDisease[100];
                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                strcpy(tempDisease, i->disease);
                strcpy(i->disease, j->disease);
                strcpy(j->disease, tempDisease);
            }
        }
    }

    // Display after sorting
    struct Patient* temp = head;
    while (temp != NULL) {
        printf("\nID: %d\nName: %s\nAge: %d\nDisease: %s\nCharges: %.2f\n",
               temp->id, temp->name, temp->age, temp->disease, temp->charges);
        temp = temp->next;
    }
}

// Count total patients
void countPatients() {
    loadFromFile();
    int count = 0;
    struct Patient* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of patients: %d\n", count);
}

// Search by ID
void searchPatient() {
    loadFromFile();
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    struct Patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nPatient Found:\nID: %d\nName: %s\nAge: %d\nDisease: %s\nCharges: %.2f\n",
                   temp->id, temp->name, temp->age, temp->disease, temp->charges);
            return;
        }
        temp = temp->next;
    }
    printf("Patient not found.\n");
}

// Modify patient record
void modifyPatient() {
    loadFromFile();
    int id;
    printf("Enter ID to modify: ");
    scanf("%d", &id);
    getchar();

    struct Patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter new Name (current: %s): ", temp->name);
            scanf(" %[^\n]", temp->name);

            printf("Enter new Age (current: %d): ", temp->age);
            scanf("%d", &temp->age);
            getchar();

            printf("Enter new Disease (current: %s): ", temp->disease);
            scanf(" %[^\n]", temp->disease);

            printf("Enter new Charges (current: %.2f): ", temp->charges);
            scanf("%f", &temp->charges);

            saveToFile();
            printf("Patient record updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Patient not found.\n");
}

// Discharge with summary
void dischargePatient() {
    loadFromFile();
    int id;
    printf("Enter ID to discharge: ");
    scanf("%d", &id);

    struct Patient *temp = head, *prev = NULL;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n--- Discharge Summary ---\n");
            printf("ID: %d\nName: %s\nAge: %d\nDisease: %s\nCharges: %.2f\n",
                   temp->id, temp->name, temp->age, temp->disease, temp->charges);

            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            saveToFile();
            printf("Patient discharged.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Patient not found.\n");
}

// Generate bill
void generateBill() {
    loadFromFile();
    int id;
    printf("Enter ID to generate bill: ");
    scanf("%d", &id);

    struct Patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n--- Bill ---\n");
            printf("Patient ID: %d\nName: %s\nDisease: %s\nCharges: %.2f\n",
                   temp->id, temp->name, temp->disease, temp->charges);
            return;
        }
        temp = temp->next;
    }
    printf("Patient not found.\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Patient Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Total Patients\n");
        printf("4. Search Patient\n");
        printf("5. Modify Patient\n");
        printf("6. Discharge Patient\n");
        printf("7. Generate Bill\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addPatient();
                    break;
            case 2: viewPatients();
                    break;
            case 3: countPatients();
                    break;
            case 4: searchPatient();
                    break;
            case 5: modifyPatient(); 
                    break;
            case 6: dischargePatient(); 
                    break;
            case 7: generateBill(); 
                    break;
            case 8: printf("Exiting...\n"); 
                    return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}