#include <vector>
#include <algorithm>

class Solution {
public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (long long)bloomDay.size()) return -1;
        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int bouquets = 0, flowers = 0;
            for (int b : bloomDay) {
                if (b <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }
            if (bouquets >= m) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};