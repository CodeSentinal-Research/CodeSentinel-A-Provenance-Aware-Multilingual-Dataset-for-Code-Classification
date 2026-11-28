#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int>& stalls, int k, int minDist) {
    int cowsPlaced = 1;
    int lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPos >= minDist) {
            cowsPlaced++;
            lastPos = stalls[i];
            if (cowsPlaced == k) return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; ++i) cin >> stalls[i];
    
    sort(stalls.begin(), stalls.end());
    
    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
