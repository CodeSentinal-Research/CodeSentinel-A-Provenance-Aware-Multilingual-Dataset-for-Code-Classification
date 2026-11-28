#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> trains(n);
    for (int i = 0; i < n; ++i) {
        cin >> trains[i].first >> trains[i].second;
    }
    
    vector<int> arrivals, departures;
    for (auto& t : trains) {
        arrivals.push_back(t.first);
        departures.push_back(t.second);
    }
    
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    
    int platforms = 1;
    int maxPlatforms = 1;
    int i = 1, j = 0;
    
    while (i < n && j < n) {
        if (arrivals[i] <= departures[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    
    cout << maxPlatforms << endl;
    return 0;
}
