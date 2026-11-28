#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int left = *std::max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        int ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int d = 1, curr = 0;
            for (int w : weights) {
                if (curr + w > mid) {
                    d++;
                    curr = w;
                } else {
                    curr += w;
                }
            }
            if (d <= days) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};