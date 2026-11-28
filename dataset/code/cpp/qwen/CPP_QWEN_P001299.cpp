#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long totalTrips;
    cin >> n >> totalTrips;
    vector<int> time(n);
    for (int i = 0; i < n; ++i) cin >> time[i];
    
    long long low = 1, high = *min_element(time.begin(), time.end()) * totalTrips;
    
    auto canComplete = [&](long long t) -> bool {
        long long trips = 0;
        for (int ti : time) {
            trips += t / ti;
            if (trips >= totalTrips) return true;
        }
        return false;
    };
    
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canComplete(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    cout << low << endl;
    return 0;
}
