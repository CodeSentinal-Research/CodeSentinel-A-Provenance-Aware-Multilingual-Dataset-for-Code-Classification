#include <iostream>
#include <unordered_map>

using namespace std;

struct Flight {
    int flightNumber;
    string source;
    string destination;
    string departureTime;
    string arrivalTime;
};

int main() {
    unordered_map<int, Flight> flights;


    int flightNumber;
    cout << "Enter the flight number to search for: ";
    cin >> flightNumber;

    if (flights.find(flightNumber) != flights.end()) {
        Flight flight = flights[flightNumber];
        cout << "Flight Information:\n";
        cout << "Flight Number: " << flight.flightNumber << "\n";
        cout << "Source: " << flight.source << "\n";
        cout << "Destination: " << flight.destination << "\n";
        cout << "Departure Time: " << flight.departureTime << "\n";
        cout << "Arrival Time: " << flight.arrivalTime << "\n";
    } else {
        cout << "Flight Not Found.\n";
    }

    return 0;
}