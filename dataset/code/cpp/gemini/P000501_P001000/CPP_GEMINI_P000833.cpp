#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

long long findPages(const std::vector<int>& arr, int k) {
    if (k > (int)arr.size()) return -1;
    long long left = *std::max_element(arr.begin(), arr.end());
    long long right = std::accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = -1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        long long mid = left + (right - left) / 2;
        int students = 1;
        long long pages = 0;
        for (int x : arr) {
            if (pages + x > mid) {
                students++;
                pages = x;
            } else {
                pages += x;
            }
        }
        if (students <= k) {
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
        std::cout << findPages(arr, k) << "\n";
    }
    return 0;
}