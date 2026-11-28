#include <iostream>
#include <unordered_map>

using namespace std;

struct Vehicle {
    string regNumber;
    string model;
    string color;
    int year;

    Vehicle(string regNumber, string model, string color, int year) : regNumber(regNumber), model(model), color(color), year(year) {}
};

int main() {
    int n;
    cin >> n;

    unordered_map<string, Vehicle*> map;

    for(int i = 0; i < n; i++) {
        string regNumber;
        string model;
        string color;
        int year;

        cin >> regNumber >> model >> color >> year;

        Vehicle* vehicle = new Vehicle(regNumber, model, color, year);
        map[regNumber] = vehicle;
    }

    string regNumberToSearch;
    cin >> regNumberToSearch;

    if(map.count(regNumberToSearch) == 0) {
        cout << "Vehicle Not Found" << endl;
    } else {
        cout << map[regNumberToSearch]->regNumber << " " << map[regNumberToSearch]->model << " " << map[regNumberToSearch]->color << " " << map[regNumberToSearch]->year << endl;
    }

    return 0;
}