#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
bool isValid(const std::vector<int>& arr, int n, int m, long long max_pages) {
    int students = 1;
    long long curr = 0;
    for (int p : arr) {
        if (p > max_pages) return false;
        if (curr + p > max_pages) {
            students++;
            curr = p;
            if (students > m) return false;
        } else {
            curr += p;
        }
    }
    return true;
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
        if (m > n) { std::cout << -1 << std::endl; return 0; }
        long long l = max_v, r = sum, ans = sum;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long long mid = l + (r - l) / 2;
            if (isValid(arr, n, m, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}