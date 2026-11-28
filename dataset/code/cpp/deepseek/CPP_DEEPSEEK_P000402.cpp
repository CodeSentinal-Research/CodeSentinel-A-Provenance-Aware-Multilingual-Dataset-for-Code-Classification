Here is a simple implementation of the problem using C++.

#include <iostream>
#include <vector>
#include <algorithm>

struct Flight {
    int origin;
    int destination;

    Flight(int o, int d) : origin(o), destination(d) {}
};

bool compareFlight(const Flight& a, const Flight& b) {
    return a.destination < b.destination;
}

int main() {
    int numberOfFlights, destination;
    std::cin >> numberOfFlights;

    std::vector<Flight> flights(numberOfFlights);
    for (int i = 0; i < numberOfFlights; i++) {
        std::cin >> flights[i].origin >> flights[i].destination;
    }

    std::cin >> destination;

    std::sort(flights.begin(), flights.end(), compareFlight);

    for (const Flight& flight : flights) {
        if (flight.destination == destination) {
            std::cout << flight.origin << " " << flight.destination << "\n";
        }
    }

    return 0;
}

This code reads the number of flights and the destination from the standard input, then reads the list of flights from the standard input. It then sorts the flights by destination and prints the flights to the standard output that match the specified destination. The compareFlight function is used to sort the flights by destination.