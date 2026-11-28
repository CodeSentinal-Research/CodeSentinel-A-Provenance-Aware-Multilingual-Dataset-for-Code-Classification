Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double minMaxDist(int n, vector<int>& stations, int k) {
    sort(stations.begin(), stations.end());

    double min_dist = stations[stations.size()/2] - stations[0];
    double max_dist = stations[n-1] - stations[0];

    for(int i = 0; i < k; i++) {
        max_dist += stations[i+1] - stations[i];
    }

    double low = min_dist, high = max_dist;
    while(high - low > 1e-6) {
        double mid = (low + high) / 2;
        if(check(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

bool check(double mid) {
    int prev = 0;
    int cnt = 0;
    for(int i = 1; i < stations.size(); i++) {
        int dist = stations[i] - stations[prev];
        if(dist < mid) {
            return false;
        }
        cnt += dist / mid;
        prev = stations[i];
    }
    return cnt >= k;
}

int main() {
    int n;
    cin >> n;

    vector<int> stations(n);
    for(int i = 0; i < n; i++) {
        cin >> stations[i];
    }

    int k;
    cin >> k;

    cout << minMaxDist(n, stations, k);

    return 0;
}
This code uses a binary search to find the minimum distance between adjacent gas stations. It calculates the maximum distance that can be achieved by adding new gas stations and checks if it is possible to reach the minimum distance. If it is, it updates the high value; otherwise, it updates the low value. The lower and upper limits for the binary search are initialized to be the minimum and maximum distances between adjacent gas stations. The `check` function checks if it is possible to reach the minimum distance by adding new gas stations.