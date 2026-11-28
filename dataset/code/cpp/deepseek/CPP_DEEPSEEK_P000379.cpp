#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Train {
    string trainNumber;
    string destination;
    string departureTime;
    string arrivalTime;
};

map<string, vector<Train>> trainsMap;

void addTrain(Train t) {
    trainsMap[t.trainNumber].push_back(t);
}

void searchTrain(string trainNumber) {
    if (trainsMap.find(trainNumber) != trainsMap.end()) {
        for (Train t : trainsMap[trainNumber]) {
            cout << "Train Number: " << t.trainNumber << "\n";
            cout << "Destination: " << t.destination << "\n";
            cout << "Departure Time: " << t.departureTime << "\n";
            cout << "Arrival Time: " << t.arrivalTime << "\n";
            cout << "\n";
        }
    } else {
        cout << "Train Not Found\n";
    }
}

int main() {
    Train t1 = {"1", "New York", "08:00", "10:00"};
    Train t2 = {"2", "Los Angeles", "09:00", "11:00"};
    Train t3 = {"3", "San Francisco", "10:00", "12:00"};

    addTrain(t1);
    addTrain(t2);
    addTrain(t3);

    string trainNumber;
    cout << "Enter train number to search: ";
    cin >> trainNumber;

    searchTrain(trainNumber);

    return 0;
}