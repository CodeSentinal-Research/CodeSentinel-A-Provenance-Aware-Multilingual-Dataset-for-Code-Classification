Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int *gas = new int[N];
    int *cost = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> gas[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    int start = 0;
    int curr_gas = 0;
    for (int i = 0; i < N; i++) {
        curr_gas += gas[i];
        if (curr_gas < cost[i]) {
            start = -1;
            break;
        } else {
            curr_gas -= cost[i];
        }
    }
    if (start != -1) {
        for (int i = 0; i < N; i++) {
            if (curr_gas + gas[start] >= cost[start]) {
                cout << start << endl;
                break;
            } else {
                curr_gas += gas[start];
                start = (start + 1) % N;
            }
        }
    } else {
        cout << -1 << endl;
    }
    delete[] gas;
    delete[] cost;
    return 0;
}

This code takes the number of gas stations N and the gas and cost information for each station as input. Then it calculates the total gas available at each station and the cost for each station. It iterates through the stations, updating the current gas and checking if it is sufficient to travel to the next station. If it's not, it stops and prints -1. If it is, it continues with the cost for the next station. If the cost is less than the remaining gas at the current station, it updates the start station and continues the process. If not, it wraps around to the next station. If no valid starting station is found, it prints -1.