#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vehicle {
    int year;
    string make;
    string model;
};

bool compare(const Vehicle& a, const Vehicle& b) {
    return a.year < b.year;
}

int main() {
    int year;
    int num_vehicles;

    cin >> year >> num_vehicles;

    vector<Vehicle> vehicles(num_vehicles);

    for (int i = 0; i < num_vehicles; i++) {
        cin >> vehicles[i].year >> vehicles[i].make >> vehicles[i].model;
    }

    sort(vehicles.begin(), vehicles.end(), compare);

    for (const auto& vehicle : vehicles) {
        if (vehicle.year > year) {
            cout << vehicle.year << ' ' << vehicle.make << ' ' << vehicle.model << '\n';
        }
    }

    return 0;
}