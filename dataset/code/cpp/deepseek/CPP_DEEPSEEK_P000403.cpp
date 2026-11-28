#include <iostream>
#include <vector>
#include <string>

struct Train {
    std::string destination;
    int departureTime;
};

int main() {
    int numTrains;
    std::string station;

    std::cin >> numTrains;

    std::cin >> station;

    std::vector<Train> trains(numTrains);
    for (int i = 0; i < numTrains; i++) {
        std::cin >> trains[i].destination >> trains[i].departureTime;
    }

    for (const auto& train : trains) {
        if (train.destination == station) {
            std::cout << train.destination << " " << train.departureTime << std::endl;
        }
    }

    return 0;
}