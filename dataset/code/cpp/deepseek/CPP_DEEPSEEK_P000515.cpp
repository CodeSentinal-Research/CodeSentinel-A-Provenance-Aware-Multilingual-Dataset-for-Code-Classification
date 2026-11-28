Here is the complete C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<double> getCollisionTimes(int n, vector<pair<int, int>>& cars) {
    vector<double> times(n, -1.0);
    if (n < 2)
        return times;

    sort(cars.begin(), cars.end());

    double currTime = (double)cars[n-1].first / (double)cars[n-1].second;
    times[n-1] = currTime;

    for (int i = n - 2; i >= 0; i--) {
        if (cars[i].second <= cars[i+1].second)
            times[i] = currTime;
        else {
            double timeToCollide = (double)cars[i].first / (double)cars[i].second + (double)cars[i+1].first / (double)cars[i+1].second;
            currTime = timeToCollide;
            times[i] = timeToCollide;
        }
    }

    return times;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cars(n);

    for (int i = 0; i < n; i++) {
        cin >> cars[i].first >> cars[i].second;
    }

    vector<double> times = getCollisionTimes(n, cars);

    for (double time : times) {
        cout << time << endl;
    }

    return 0;
}

This code first sorts the cars based on their positions. Then it calculates the time of each car to the next car. If the current car's speed is greater than or equal to the next car's speed, the car doesn't collide and the time is -1. Otherwise, the car collides with the next car and the time is the time to collide. The time to collide is calculated by dividing the positions of the two cars and adding them together.