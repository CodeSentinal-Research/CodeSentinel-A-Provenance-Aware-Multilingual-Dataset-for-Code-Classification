// Header files for input/output, memory allocation, string manipulation, and time functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure definition for storing flight information
struct Flight {
    char flightname[30];          // Name/ID of the flight
    char pickup[30];              // Departure location
    char destination[30];         // Arrival location
    int businessclass;            // Number of business class seats
    int economy;                  // Number of economy class seats
    int availableseats;          // Total available seats
    char timing[10];             // Flight timing in HH:MM format
};

// Structure definition for storing passenger booking information
struct Passenger {
    char name[50];               // Passenger name
    char passengerseat[50];      // Seat type (Business/Economy)
    char flightname[30];         // Associated flight name
    char bookingRef[15];         // Unique booking reference
};

// Global variables for managing flights and passengers
struct Flight *flights = NULL;    // Dynamic array of flights
struct Passenger *passengers = NULL; // Dynamic array of passengers
int flightCount = 0;             // Current number of flights
int passengerCount = 0;          // Current number of passengers
int flightCapacity = 10;         // Initial capacity for flights array
int passengerCapacity = 10;      // Initial capacity for passengers array
const char *VERIFICATION_CODE = "1234"; // Admin access code

// Function prototypes
void initialize();
void addFlight();
void removeFlight();
void modifyFlight();
void displayFlights();
void bookFlight();
void cancelBooking();
void searchFlights();
void viewBookingDetails();
void saveDataToFile();
void loadDataFromFile();
int verifyUser();
void generateBookingRef(char *ref);

// Utility function prototypes
int validateTimeFormat(const char *time);
void resizeFlights();
void resizePassengers();

// Main function - Entry point of the program
int main() {
    initialize();    // Initialize system resources

    int option;
    printf("***** Welcome to ABC International Airlines *****\n");
    
    // Main program loop
    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. View Flights\n");
        printf("2. Book Flight\n");
        printf("3. Cancel Booking\n");
        printf("4. Search Flights\n");
        printf("5. View Booking Details\n");
        printf("6. Add Flight (Authorized Only)\n");
        printf("7. Remove Flight (Authorized Only)\n");
        printf("8. Modify Flight (Authorized Only)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        // Process user choice
        switch (option) {
            case 1: displayFlights(); break;
            case 2: bookFlight(); break;
            case 3: cancelBooking(); break;
            case 4: searchFlights(); break;
            case 5: viewBookingDetails(); break;
            case 6: addFlight(); break;
            case 7: removeFlight(); break;
            case 8: modifyFlight(); break;
            case 0: 
                saveDataToFile();
                printf("Exiting... Thank you for using ABC Airlines!\n");
                break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (option != 0);

    // Cleanup: Free allocated memory
    free(flights);
    free(passengers);

    return 0;
}

// Initialize program by allocating memory and loading saved data
void initialize() {
    flights = (struct Flight*)malloc(300 * sizeof(struct Flight));
    passengers = (struct Passenger*)malloc(300 * sizeof(struct Passenger)); 
    loadDataFromFile();
}

// Add a new flight to the system (Admin only)
void addFlight() {
    if (!verifyUser()) return;   // Verify admin credentials

    if (flightCount == flightCapacity) resizeFlights();  // Expand array if needed

    // Get flight details from user
    struct Flight newFlight;
    printf("Enter Flight Name: ");
    scanf("%s", newFlight.flightname);
    printf("Enter Pickup Location: ");
    scanf("%s", newFlight.pickup);
    printf("Enter Destination: ");
    scanf("%s", newFlight.destination);
    printf("Enter Business Class Seats: ");
    scanf("%d", &newFlight.businessclass);
    printf("Enter Economy Seats: ");
    scanf("%d", &newFlight.economy);
    printf("Enter Timing (HH:MM): ");
    scanf("%s", newFlight.timing);

    // Validate time format
    if (!validateTimeFormat(newFlight.timing)) {
        printf("Invalid time format. Flight not added.\n");
        return;
    }

    // Calculate total available seats and add flight
    newFlight.availableseats = newFlight.businessclass + newFlight.economy;
    flights[flightCount++] = newFlight;
    printf("Flight successfully added!\n");
}

// Remove a flight from the system (Admin only)
void removeFlight() {
    if (!verifyUser()) return;   // Verify admin credentials

    displayFlights();
    int flightNum;
    printf("Enter the flight number to remove: ");
    scanf("%d", &flightNum);

    // Validate flight number
    if (flightNum < 1 || flightNum > flightCount) {
        printf("Invalid flight number.\n");
        return;
    }

    // Shift remaining flights to fill the gap
    for (int i = flightNum - 1; i < flightCount - 1; i++) {
        flights[i] = flights[i + 1];
    }
    flightCount--;
    printf("Flight successfully removed!\n");
}

// Windows-specific sound functions
#include <windows.h>

// Play a beep sound with given frequency and duration
void playSound(int frequency, int duration) {
    Beep(frequency, duration);
}

// Generate and display booking receipt with sound effects
void generateReceipt(struct Passenger *passenger, struct Flight *flight) {
    printf("\n------------------------------------------------------------\n");
    printf("                    ABC International Airlines               \n");
    printf("------------------------------------------------------------\n");
    printf("                      BOOKING RECEIPT                       \n");
    printf("------------------------------------------------------------\n");

    playSound(500, 500); // Initial sound effect

    // Print passenger and flight details
    printf("Passenger Name: %-30s\n", passenger->name);
    printf("Flight Name: %-32s\n", flight->flightname);
    printf("Pickup Location: %-26s\n", flight->pickup);
    printf("Destination: %-30s\n", flight->destination);
    printf("Seat Type: %-30s\n", passenger->passengerseat);
    printf("Booking Reference: %-17s\n", passenger->bookingRef);
    
    playSound(600, 300); // Mid-receipt sound

    // Display seat availability and pricing
    printf("Business Class Seats Left: %-5d  |  Economy Seats Left: %-5d\n", 
           flight->businessclass, flight->economy);
    int price = (strcmp(passenger->passengerseat, "Business") == 0) ? 1000 : 500;
    printf("Price: $%-33d\n", price);
    
    playSound(700, 400); // Final sound
    
    printf("------------------------------------------------------------\n");
    printf("Thank you for choosing ABC International Airlines!\n");
    printf("------------------------------------------------------------\n");
}

// Modify existing flight details (Admin only)
void modifyFlight() {
    if (!verifyUser()) return;

    displayFlights();
    int flightNum;
    printf("Enter the flight number to modify: ");
    scanf("%d", &flightNum);

    if (flightNum < 1 || flightNum > flightCount) {
        printf("Invalid flight number.\n");
        return;
    }

    // Update flight details
    struct Flight *flight = &flights[flightNum - 1];
    printf("Modify Flight Name (current: %s): ", flight->flightname);
    scanf("%s", flight->flightname);
    printf("Modify Pickup Location (current: %s): ", flight->pickup);
    scanf("%s", flight->pickup);
    printf("Modify Destination (current: %s): ", flight->destination);
    scanf("%s", flight->destination);
    printf("Modify Business Class Seats (current: %d): ", flight->businessclass);
    scanf("%d", &flight->businessclass);
    printf("Modify Economy Seats (current: %d): ", flight->economy);
    scanf("%d", &flight->economy);
    printf("Modify Timing (current: %s): ", flight->timing);
    scanf("%s", flight->timing);

    // Validate new time format
    if (!validateTimeFormat(flight->timing)) {
        printf("Invalid time format. Changes not saved.\n");
        return;
    }

    flight->availableseats = flight->businessclass + flight->economy;
    printf("Flight successfully modified!\n");
}

// Display all available flights
void displayFlights() {
    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }

    // Print details of each flight
    for (int i = 0; i < flightCount; i++) {
        printf("Flight %d: %s | From: %s | To: %s | Business: %d | Economy: %d | Timing: %s\n",
               i + 1, flights[i].flightname, flights[i].pickup, flights[i].destination,
               flights[i].businessclass, flights[i].economy, flights[i].timing);
    }
}

// Search flights by destination
void searchFlights() {
    char destination[30];
    printf("Enter destination to search flights: ");
    scanf("%s", destination);

    printf("Flights to %s:\n", destination);
    int found = 0;
    
    // Search and display matching flights
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].destination, destination) == 0) {
            printf("Flight %d: %s | Timing: %s\n", 
                   i + 1, flights[i].flightname, flights[i].timing);
            found = 1;
        }
    }

    if (!found) printf("No flights found for the destination.\n");
}

// Book flight tickets for passengers
void bookFlight() {
    displayFlights();
    int choice;
    printf("Enter the number of the flight to book: ");
    scanf("%d", &choice);

    // Validate flight selection
    if (choice < 1 || choice > flightCount) {
        printf("Invalid flight number.\n");
        return;
    }

    struct Flight *flight = &flights[choice - 1];
    if (flight->availableseats == 0) {
        printf("No seats available on this flight.\n");
        return;
    }

    int numTickets;
    printf("Enter the number of tickets you want to book: ");
    scanf("%d", &numTickets);

    // Check seat availability
    if (numTickets > flight->availableseats) {
        printf("Not enough seats available. Only %d seats remaining.\n", 
               flight->availableseats);
        return;
    }

    // Resize passengers array if needed
    if (passengerCount + numTickets > passengerCapacity) resizePassengers();

    // Book tickets for each passenger
    for (int i = 0; i < numTickets; i++) {
        struct Passenger newPassenger;
        printf("Enter Passenger %d Name: ", i + 1);
        scanf("%s", newPassenger.name);

        // Seat selection
        int seatChoice;
        printf("Select Seat Type:\n1. Business\n2. Economy\nEnter your choice: ");
        scanf("%d", &seatChoice);

        // Process seat selection
        if (seatChoice == 1 && flight->businessclass > 0) {
            flight->businessclass--;
            strcpy(newPassenger.passengerseat, "Business");
        } else if (seatChoice == 2 && flight->economy > 0) {
            flight->economy--;
            strcpy(newPassenger.passengerseat, "Economy");
        } else {
            printf("No available seats in the selected class.\n");
            i--;
            continue;
        }

        // Complete booking process
        flight->availableseats--;
        strcpy(newPassenger.flightname, flight->flightname);
        generateBookingRef(newPassenger.bookingRef);
        passengers[passengerCount++] = newPassenger;

        printf("Booking successful for %s! Booking Reference: %s\n", 
               newPassenger.name, newPassenger.bookingRef);
        generateReceipt(&newPassenger, flight);
    }
}

// Display all booking details
void viewBookingDetails() {
    if (passengerCount == 0) {
        printf("No bookings found.\n");
        return;
    }

    // Display all bookings
    for (int i = 0; i < passengerCount; i++) {
        printf("Booking %d: %s | Flight: %s | Seat: %s | Ref: %s\n",
               i + 1, passengers[i].name, passengers[i].flightname, 
               passengers[i].passengerseat, passengers[i].bookingRef);
    }
}

// Cancel existing booking
void cancelBooking() {
    char ref[15];
    printf("Enter booking reference to cancel: ");
    scanf("%s", ref);

    // Search for booking and process cancellation
    for (int i = 0; i < passengerCount; i++) {
        if (strcmp(passengers[i].bookingRef, ref) == 0) {
            struct Passenger *p = &passengers[i];
            
            // Update flight seat availability
            for (int j = 0; j < flightCount; j++) {
                if (strcmp(flights[j].flightname, p->flightname) == 0) {
                    if (strcmp(p->passengerseat, "Business") == 0) {
                        flights[j].businessclass++;
                    } else if (strcmp(p->passengerseat, "Economy") == 0) {
                        flights[j].economy++;
                    }
                    flights[j].availableseats++;
                }
            }

            // Remove passenger record
            for (int k = i; k < passengerCount - 1; k++) {
                passengers[k] = passengers[k + 1];
            }
            passengerCount--;
            printf("Booking successfully cancelled.\n");
            return;
        }
    }

    printf("No booking found with the provided reference.\n");
}

// Resize flights array when capacity is reached
void resizeFlights() {
    flightCapacity *= 2;
    flights = (struct Flight*)realloc(flights, flightCapacity * sizeof(struct Flight));
    if (flights == NULL) {
        printf("Memory allocation failed while resizing flights array.\n");
        exit(1);
    }
}

// Resize passengers array when capacity is reached
void resizePassengers() {
    passengerCapacity *= 2;
    passengers = (struct Passenger*)realloc(passengers, 
                passengerCapacity * sizeof(struct Passenger));
    if (passengers == NULL) {
        printf("Memory allocation failed while resizing passengers array.\n");
        exit(1);
    }
}

// Validate time format (HH:MM)
int validateTimeFormat(const char *time) {
    if (strlen(time) != 5 || time[2] != ':') return 0;
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');
    return hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59;
}

// Verify admin access
int verifyUser() {
    char code[10];
    printf("Enter verification code: ");
    scanf("%s", code);
    if (strcmp(code, VERIFICATION_CODE) == 0) return 1;
    printf("Invalid code.\n");
    return 0;
}

// Generate unique booking reference
void generateBookingRef(char *ref) {
    srand(time(NULL));
    sprintf(ref, "%d%d%d", rand() % 1000, rand() % 1000, rand() % 1000);
}

// Save all data to files
void saveDataToFile() {
    // Save flights data
    FILE *flightFile = fopen("flights.txt", "w");
    if (!flightFile) {
        perror("Error opening flights file for writing");
        return;
    }

    fprintf(flightFile, "%d\n", flightCount);
    for (int i = 0; i < flightCount; i++) {
        fprintf(flightFile, "%s %s %s %d %d %d %s\n",
                flights[i].flightname, flights[i].pickup, flights[i].destination,
                flights[i].businessclass, flights[i].economy,
                flights[i].availableseats, flights[i].timing);
    }
    fclose(flightFile);

    // Save passengers data
    FILE *passengerFile = fopen("passengers.txt", "w");
    if (!passengerFile) {
        perror("Error opening passengers file for writing");
        return;
    }

    fprintf(passengerFile, "%d\n", passengerCount);
    for (int i = 0; i < passengerCount; i++) {
        fprintf(passengerFile, "%s %s %s %s\n",
                passengers[i].name, passengers[i].passengerseat,
                passengers[i].flightname, passengers[i].bookingRef);
    }
    fclose(passengerFile);

    printf("Data successfully saved to files.\n");
}

// Load data from files
void loadDataFromFile() {
    // Load flights data
    FILE *flightFile = fopen("flights.txt", "r");
    if (!flightFile) {
        printf("Flight data file not found. Creating a new file...\n");
        flightFile = fopen("flights.txt", "w");
        if (!flightFile) {
            perror("Error creating flight file");
            exit(1);
        }
        fclose(flightFile);
        return;
    }

    fscanf(flightFile, "%d\n", &flightCount);
    for (int i = 0; i < flightCount; i++) {
        fscanf(flightFile, "%s %s %s %d %d %d %s\n",
               flights[i].flightname, flights[i].pickup, flights[i].destination,
               &flights[i].businessclass, &flights[i].economy,
               &flights[i].availableseats, flights[i].timing);
    }
    fclose(flightFile);
    printf("Successfully loaded %d flights.\n", flightCount);

    // Load passengers data
    FILE *passengerFile = fopen("passengers.txt", "r");
    if (!passengerFile) {
        printf("Passenger data file not found. Creating a new file...\n");
        passengerFile = fopen("passengers.txt", "w");
        if (!passengerFile) {
            perror("Error creating passengers file");
            exit(1);
        }
        fclose(passengerFile);
        return;
    }

    fscanf(passengerFile, "%d\n", &passengerCount);
    for (int i = 0; i < passengerCount; i++) {
        fscanf(passengerFile, "%s %s %s %s\n",
               passengers[i].name, passengers[i].passengerseat,
               passengers[i].flightname, passengers[i].bookingRef);
    }
    fclose(passengerFile);
    printf("Successfully loaded %d passengers.\n", passengerCount);
}