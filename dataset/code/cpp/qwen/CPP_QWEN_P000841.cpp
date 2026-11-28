#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDistribute(const vector<int>& candies, long long k, long long perChild) {
    if (perChild == 0) return true;
    long long childrenFed = 0;
    for (int c : candies) {
        childrenFed += c / perChild;
    }
    return childrenFed >= k;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> candies(n);
    for (int i = 0; i < n; ++i) cin >> candies[i];
    
    long long low = 1;
    long long high = *max_element(candies.begin(), candies.end());
    long long ans = 0;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canDistribute(candies, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
