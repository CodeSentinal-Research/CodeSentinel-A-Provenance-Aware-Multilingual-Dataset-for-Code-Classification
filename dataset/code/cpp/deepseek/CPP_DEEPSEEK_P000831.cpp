Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDays(int n, vector<long long> bloomDay, int m, int k) {
    if (m > n) return -1;

    long long left = 1;
    long long right = *max_element(bloomDay.begin(), bloomDay.end());
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (check(n, bloomDay, mid, k)) left = mid + 1;
        else right = mid;
    }
    return left;
}

bool check(int n, vector<long long>& bloomDay, long long limit, int k) {
    int count = 0;
    int bouquets = 0;
    for (int i = 0; i < n; i++) {
        if (bloomDay[i] <= limit) {
            count++;
            if (count == k) {
                count = 0;
                bouquets++;
            }
        } else {
            count = 0;
        }
    }
    return bouquets == n / k;
}

int main() {
    int n;
    vector<long long> bloomDay;
    int m;
    int k;

    cin >> n;
    bloomDay.resize(n);
    for (int i = 0; i < n; i++) cin >> bloomDay[i];
    cin >> m >> k;

    cout << minDays(n, bloomDay, m, k) << "\n";

    return 0;
}
This code first checks if it is possible to make m bouquets with k adjacent flowers. If it is not possible, it uses binary search to find the minimum number of days required. The `check` function checks if a given limit can make m bouquets with k adjacent flowers. The `minDays` function uses this `check` function to find the minimum number of days required.