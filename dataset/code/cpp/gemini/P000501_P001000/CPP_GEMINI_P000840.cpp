#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        int left = 1, right = *std::max_element(nums.begin(), nums.end());
        int ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            long long ops = 0;
            for (int x : nums) {
                ops += (x - 1) / mid;
            }
            if (ops <= maxOperations) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};