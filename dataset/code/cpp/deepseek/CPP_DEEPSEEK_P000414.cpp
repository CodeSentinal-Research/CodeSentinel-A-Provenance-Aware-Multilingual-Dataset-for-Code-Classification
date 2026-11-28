#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flight {
    int flightNumber;
    int price;
    int budget;
};

bool flightMatch(Flight f1, Flight f2) {
    return f1.price <= f2.budget;
}

void findFlights(vector<Flight>& flights, int maxBudget) {
    vector<Flight> matches;

    for (int i = 0; i < flights.size(); i++) {
        for (int j = i + 1; j < flights.size(); j++) {
            if (flightMatch(flights[i], flights[j])) {
                matches.push_back(flights[i]);
                break;
            }
        }
    }

    for (Flight f : matches) {
        if (f.price <= maxBudget) {
            cout << "Flight Number: " << f.flightNumber << ", Price: " << f.price << ", Budget: " << f.budget << endl;
        }
    }
}

int main() {
    int maxBudget;
    int numFlights;

    cin >> numFlights >> maxBudget;

    vector<Flight> flights(numFlights);

    for (int i = 0; i < numFlights; i++) {
        cin >> flights[i].flightNumber >> flights[i].price >> flights[i].budget;
    }

    findFlights(flights, maxBudget);

    return 0;
}