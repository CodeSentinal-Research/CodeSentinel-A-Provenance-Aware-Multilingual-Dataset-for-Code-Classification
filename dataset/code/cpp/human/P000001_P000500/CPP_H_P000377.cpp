#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Vehicle Class Definition
class Vehicle {
private:
    string regNumber;
    string brand;
    string model;
    int year;
    double price;

public:
    // Constructor
    Vehicle() {}
    Vehicle(string reg, string b, string m, int y, double p) {
        regNumber = reg;
        brand = b;
        model = m;
        year = y;
        price = p;
    }

    // Function to input data
    void input() {
        cout << "Enter Registration Number: ";
        cin >> regNumber;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Price: ";
        cin >> price;
    }

    // Function to display data
    void display() const {
        cout << left << setw(15) << regNumber
             << setw(15) << brand
             << setw(15) << model
             << setw(10) << year
             << setw(10) << price << endl;
    }

    // Get registration number (for search/delete)
    string getRegNumber() const {
        return regNumber;
    }

    // Write object to file
    void writeToFile(ofstream &out) {
        out << regNumber << " " << brand << " " << model << " "
            << year << " " << price << endl;
    }

    // Read object from file
    bool readFromFile(ifstream &in) {
        in >> regNumber >> brand >> model >> year >> price;
        return !in.fail();
    }
};

// Function Prototypes
void addVehicle();
void displayVehicles();
void searchVehicle();
void deleteVehicle();

int main() {
    int choice;

    do {
        cout << "\n========== VEHICLE MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display All Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Delete Vehicle\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: displayVehicles(); break;
            case 3: searchVehicle(); break;
            case 4: deleteVehicle(); break;
            case 5: cout << "Exiting... Data saved successfully.\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a vehicle
void addVehicle() {
    Vehicle v;
    v.input();

    ofstream file("vehicles.txt", ios::app);
    v.writeToFile(file);
    file.close();

    cout << "\n✅ Vehicle added successfully!\n";
}

// Function to display all vehicles
void displayVehicles() {
    ifstream file("vehicles.txt");
    Vehicle v;

    cout << "\n================ VEHICLE LIST ================\n";
    cout << left << setw(15) << "RegNumber"
         << setw(15) << "Brand"
         << setw(15) << "Model"
         << setw(10) << "Year"
         << setw(10) << "Price" << endl;
    cout << "-----------------------------------------------\n";

    while (v.readFromFile(file)) {
        v.display();
    }

    file.close();
}

// Function to search vehicle by registration number
void searchVehicle() {
    string reg;
    cout << "Enter Registration Number to Search: ";
    cin >> reg;

    ifstream file("vehicles.txt");
    Vehicle v;
    bool found = false;

    while (v.readFromFile(file)) {
        if (v.getRegNumber() == reg) {
            cout << "\nVehicle Found:\n";
            v.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "❌ Vehicle not found.\n";

    file.close();
}

// Function to delete vehicle
void deleteVehicle() {
    string reg;
    cout << "Enter Registration Number to Delete: ";
    cin >> reg;

    ifstream file("vehicles.txt");
    ofstream temp("temp.txt");

    Vehicle v;
    bool found = false;

    while (v.readFromFile(file)) {
        if (v.getRegNumber() != reg)
            v.writeToFile(temp);
        else
            found = true;
    }

    file.close();
    temp.close();

    remove("vehicles.txt");
    rename("temp.txt", "vehicles.txt");

    if (found)
        cout << "✅ Vehicle deleted successfully.\n";
    else
        cout << "❌ Vehicle not found.\n";
}
