#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Train {
    int trainNo;
    char trainName[50];
    int totalSeats;
    int availableSeats;
    struct Train *next;
};

struct Train *head = NULL;
void addTrain() {
    struct Train *newTrain = (struct Train*)malloc(sizeof(struct Train));

    printf("Enter Train Number: ");
    scanf("%d", &newTrain->trainNo);

    printf("Enter Train Name: ");
    scanf(" %[^\n]", newTrain->trainName);

    printf("Enter Total Seats: ");
    scanf("%d", &newTrain->totalSeats);

    newTrain->availableSeats = newTrain->totalSeats;
    newTrain->next = head;
    head = newTrain;

    printf("Train added successfully!\n");
}
void displayTrains() {
    struct Train *temp = head;

    if (temp == NULL) {
        printf("No trains available.\n");
        return;
    }

    while (temp != NULL) {
        printf("\nTrain No: %d", temp->trainNo);
        printf("\nName: %s", temp->trainName);
        printf("\nAvailable Seats: %d\n", temp->availableSeats);
        temp = temp->next;
    }
}
void searchTrain() {
    int num;
    printf("Enter Train Number to search: ");
    scanf("%d", &num);

    struct Train *temp = head;

    while (temp != NULL) {
        if (temp->trainNo == num) {
            printf("\nTrain Found!");
            printf("\nName: %s", temp->trainName);
            printf("\nAvailable Seats: %d\n", temp->availableSeats);
            return;
        }
        temp = temp->next;
    }

    printf("Train not found.\n");
}
void bookTicket() {
    int num, seats;
    printf("Enter Train Number: ");
    scanf("%d", &num);

    struct Train *temp = head;

    while (temp != NULL) {
        if (temp->trainNo == num) {
            printf("Enter number of seats: ");
            scanf("%d", &seats);

            if (temp->availableSeats >= seats) {
                temp->availableSeats -= seats;
                printf("Booking successful!\n");
            } else {
                printf("Not enough seats available.\n");
            }
            return;
        }
        temp = temp->next;
    }

    printf("Train not found.\n");
}
void cancelTicket() {
    int num, seats;
    printf("Enter Train Number: ");
    scanf("%d", &num);

    struct Train *temp = head;

    while (temp != NULL) {
        if (temp->trainNo == num) {
            printf("Enter number of seats to cancel: ");
            scanf("%d", &seats);

            temp->availableSeats += seats;
            printf("Cancellation successful!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Train not found.\n");
}
int main() {
    int choice;

    while (1) {
        printf("\n--- Train Management System ---\n");
        printf("1. Add Train\n");
        printf("2. Display Trains\n");
        printf("3. Search Train\n");
        printf("4. Book Ticket\n");
        printf("5. Cancel Ticket\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTrain(); break;
            case 2: displayTrains(); break;
            case 3: searchTrain(); break;
            case 4: bookTicket(); break;
            case 5: cancelTicket(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}