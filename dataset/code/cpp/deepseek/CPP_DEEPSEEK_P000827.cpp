#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findRadius(vector<int>& heaters, vector<int>& houses) {
    sort(heaters.begin(), heaters.end());
    
    int minRadius = INT_MAX;
    for (int i = 0; i < heaters.size(); i++) {
        int left = heaters[i], right = heaters[i];
        while (i < heaters.size() - 1 && abs(heaters[i+1] - heaters[i]) <= right) {
            right = max(right, heaters[i+1]);
            i++;
        }
        minRadius = min(minRadius, right - left);
    }
    
    return minRadius;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> heaters(m);
    for (int i = 0; i < m; i++) {
        cin >> heaters[i];
    }
    
    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }
    
    cout << findRadius(heaters, houses);
    
    return 0;
}
This code first sorts the heaters array. Then for each house, it finds the minimum right bound (right) that it can cover by heaters and calculates the distance between left and right. The minimum distance is updated if it is smaller than the current minimum distance. After scanning all houses, the minimum distance is returned.