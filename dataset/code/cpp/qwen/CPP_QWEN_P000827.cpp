#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> houses(n);
    for (int i = 0; i < n; ++i) cin >> houses[i];
    cin >> m;
    vector<int> heaters(m);
    for (int i = 0; i < m; ++i) cin >> heaters[i];
    
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    
    int minRadius = 0;
    for (int house : houses) {
        // Find closest heater
        auto it = lower_bound(heaters.begin(), heaters.end(), house);
        int dist = INT_MAX;
        if (it != heaters.end()) {
            dist = min(dist, abs(*it - house));
        }
        if (it != heaters.begin()) {
            dist = min(dist, abs(*(it - 1) - house));
        }
        minRadius = max(minRadius, dist);
    }
    
    cout << minRadius << endl;
    return 0;
}
