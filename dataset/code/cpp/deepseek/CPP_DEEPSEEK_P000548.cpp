Here is the code:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minBuses(vector<vector<int>> routes, int source, int target) {
    vector<int> visited(500, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    int minBuses = 0;

    while (!pq.empty()) {
        int stopCount = pq.size();
        for (int i = 0; i < stopCount; i++) {
            int currentStop = pq.front().second;
            pq.pop();

            for (int j = 0; j < routes[currentStop].size(); j++) {
                int nextStop = routes[currentStop][j];

                if (nextStop == target) {
                    return minBuses + 1;
                }

                if (!visited[nextStop]) {
                    visited[nextStop] = true;
                    pq.push({minBuses + 1, nextStop});
                }
            }
        }

        minBuses++;
    }

    return -1;
}

int main() {
    int numRoutes;
    cin >> numRoutes;

    vector<vector<int>> routes(numRoutes);
    for (int i = 0; i < numRoutes; i++) {
        int numStops;
        cin >> numStops;

        vector<int> route(numStops);
        for (int j = 0; j < numStops; j++) {
            cin >> route[j];
        }

        routes[i] = route;
    }

    int source, target;
    cin >> source >> target;

    int minBuses = minBuses(routes, source, target);

    if (minBuses == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << minBuses << endl;
    }

    return 0;
}

In this code, we use a priority queue to keep track of the bus stops to visit. The priority queue is used because the next stop to visit should be the one with the smallest bus count. This ensures that we always visit the bus stop with the fewest buses first. If the target is reached, we return the minimum number of buses, otherwise, we keep adding buses until we reach the target. If it is not possible to reach the target, we return -1.