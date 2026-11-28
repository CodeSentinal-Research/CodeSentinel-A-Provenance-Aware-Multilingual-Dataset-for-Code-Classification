#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSelectCandies(const vector<int>& price, int k, int minTastiness) {
    int count = 1;
    int lastPrice = price[0];
    for (int i = 1; i < price.size(); ++i) {
        if (price[i] - lastPrice >= minTastiness) {
            count++;
            lastPrice = price[i];
            if (count == k) return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> price(n);
    for (int i = 0; i < n; ++i) cin >> price[i];
    
    sort(price.begin(), price.end());
    
    int low = 0;
    int high = price.back() - price.front();
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canSelectCandies(price, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
