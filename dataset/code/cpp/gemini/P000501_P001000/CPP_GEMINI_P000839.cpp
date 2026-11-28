#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int left = 1, right = *std::max_element(nums.begin(), nums.end());
        int ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int total = 0;
            for (int x : nums) {
                total += (x + mid - 1) / mid;
            }
            if (total <= threshold) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};