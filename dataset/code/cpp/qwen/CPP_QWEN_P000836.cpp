#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceBalls(const vector<int>& position, int m, int minDist) {
    int ballsPlaced = 1;
    int lastPos = position[0];
    for (int i = 1; i < position.size(); ++i) {
        if (position[i] - lastPos >= minDist) {
            ballsPlaced++;
            lastPos = position[i];
            if (ballsPlaced == m) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> position(n);
    for (int i = 0; i < n; ++i) cin >> position[i];
    
    sort(position.begin(), position.end());
    
    int low = 1;
    int high = position.back() - position.front();
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceBalls(position, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
