#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

long long paintersPartition(const std::vector<int>& arr, int k) {
    long long left = *std::max_element(arr.begin(), arr.end());
    long long right = std::accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        long long mid = left + (right - left) / 2;
        int painters = 1;
        long long curr = 0;
        for (int x : arr) {
            if (curr + x > mid) {
                painters++;
                curr = x;
            } else {
                curr += x;
            }
        }
        if (painters <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    if (std::cin >> n >> k && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << paintersPartition(arr, k) << "\n";
    }
    return 0;
}