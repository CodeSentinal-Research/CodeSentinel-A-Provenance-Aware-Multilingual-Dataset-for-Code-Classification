#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Vehicle {
    string manufacturer;
    string model;
};

int main() {
    int n;
    cin >> n;

    vector<Vehicle> vehicles(n);

    for (int i = 0; i < n; i++) {
        cin >> vehicles[i].manufacturer;
        cin >> vehicles[i].model;
    }

    string manufacturerToSearch;
    cin >> manufacturerToSearch;

    int count = 0;
    for (const Vehicle& vehicle : vehicles) {
        if (vehicle.manufacturer == manufacturerToSearch) {
            cout << vehicle.manufacturer << " " << vehicle.model << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "No vehicles found" << endl;
    }

    return 0;
}

This C++ code will first read the number of vehicles and then read each vehicle record. It then reads the name of the manufacturer to search for. It iterates over the list of vehicles, checking if each vehicle's manufacturer matches the search term. If it does, it prints the vehicle's details. If no vehicles match, it outputs a message indicating no vehicles were found.