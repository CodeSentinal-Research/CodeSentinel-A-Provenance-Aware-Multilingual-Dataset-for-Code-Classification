#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int day) {
    int bouquets = 0;
    int flowers = 0;
    for (int d : bloomDay) {
        if (d <= day) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
    }
    return bouquets >= m;
}

int main() {
    int n, m, k;
    cin >> n;
    vector<int> bloomDay(n);
    for (int i = 0; i < n; ++i) cin >> bloomDay[i];
    cin >> m >> k;
    
    if ((long long)m * k > n) {
        cout << -1 << endl;
        return 0;
    }
    
    int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canMakeBouquets(bloomDay, m, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
