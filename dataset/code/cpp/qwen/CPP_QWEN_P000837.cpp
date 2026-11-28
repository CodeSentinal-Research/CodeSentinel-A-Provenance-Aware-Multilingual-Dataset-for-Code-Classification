#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool canAddStations(const vector<int>& stations, int k, double maxDist) {
    int stationsAdded = 0;
    for (int i = 0; i < stations.size() - 1; ++i) {
        double dist = stations[i+1] - stations[i];
        stationsAdded += (int)(dist / maxDist);
        // If dist is exactly divisible, we don't need a station at the end point itself if it's already there, 
        // but the problem implies adding new ones between.
        // Standard logic: ceil(dist / maxDist) - 1
        if (dist / maxDist == (int)(dist / maxDist)) {
             stationsAdded--;
        }
        if (stationsAdded > k) return false;
    }
    return stationsAdded <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stations(n);
    for (int i = 0; i < n; ++i) cin >> stations[i];
    
    double low = 0.0;
    double high = 1e8;
    
    for (int iter = 0; iter < 100; ++iter) {
        double mid = low + (high - low) / 2.0;
        if (canAddStations(stations, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    cout << fixed << setprecision(6) << high << endl;
    return 0;
}
