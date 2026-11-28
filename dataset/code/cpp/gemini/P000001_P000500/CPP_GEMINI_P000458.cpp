#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
bool canSplit(const std::vector<int>& arr, int m, long long max_sum) {
    int count = 1;
    long long curr = 0;
    for (int v : arr) {
        if (curr + v > max_sum) { count++; curr = v; }
        else curr += v;
    }
    return count <= m;
}
int main() {
    int n, m;
    if (std::cin >> n >> m) {
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
            if (canSplit(arr, m, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}