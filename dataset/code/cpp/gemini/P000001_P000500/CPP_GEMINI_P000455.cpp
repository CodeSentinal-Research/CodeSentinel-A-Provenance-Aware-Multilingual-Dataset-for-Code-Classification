#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
bool canShip(const std::vector<int>& arr, int d, long long cap) {
    int days = 1;
    long long curr = 0;
    for (int w : arr) {
        if (curr + w > cap) {
            days++;
            curr = w;
        } else {
            curr += w;
        }
    }
    return days <= d;
}
int main() {
    int n, d;
    if (std::cin >> n >> d) {
        std::vector<int> arr(n);
        long long sum = 0, max_v = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            sum += arr[i];
            if (arr[i] > max_v) max_v = arr[i];
        }
        long long l = max_v, r = sum, ans = sum;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long long mid = l + (r - l) / 2;
            if (canShip(arr, d, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}