#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solve(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;
    unordered_map<int, vector<int>> stop_to_routes;
    for (int i = 0; i < routes.size(); i++) {
        for (int stop : routes[i]) stop_to_routes[stop].push_back(i);
    }
    queue<int> q; q.push(source);
    unordered_set<int> visited_stops, visited_routes;
    visited_stops.insert(source);
    int buses = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int curr = q.front(); q.pop();
            if (curr == target) return buses;
            for (int r : stop_to_routes[curr]) {
                if (visited_routes.count(r)) continue;
                visited_routes.insert(r);
                for (int stop : routes[r]) {
                    if (!visited_stops.count(stop)) {
                        visited_stops.insert(stop); q.push(stop);
                    }
                }
            }
        }
        buses++;
    }
    return -1;
}

int main() {
    int r; cin >> r;
    vector<vector<int>> routes(r);
    for(int i = 0; i < r; i++) {
        int sz; cin >> sz; routes[i].resize(sz);
        for(int j = 0; j < sz; j++) cin >> routes[i][j];
    }
    int src, tgt; cin >> src >> tgt;
    cout << solve(routes, src, tgt) << endl;
    return 0;
}
