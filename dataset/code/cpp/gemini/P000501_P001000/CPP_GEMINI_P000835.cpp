#include <iostream>
#include <vector>
#include <algorithm>

int aggressiveCows(std::vector<int>& stalls, int k) {
    std::sort(stalls.begin(), stalls.end());
    int left = 1, right = stalls.back() - stalls.front();
    int ans = 1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        int cows = 1, last = stalls[0];
        for (size_t i = 1; i < stalls.size(); i++) {
            if (stalls[i] - last >= mid) {
                cows++;
                last = stalls[i];
            }
        }
        if (cows >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    if (std::cin >> n >> k && n > 0) {
        std::vector<int> stalls(n);
        for (int i = 0; i < n; i++) std::cin >> stalls[i];
        std::cout << aggressiveCows(stalls, k) << "\n";
    }
    return 0;
}