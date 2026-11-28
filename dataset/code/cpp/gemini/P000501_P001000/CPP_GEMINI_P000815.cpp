#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto findBound = [&](bool isFirst) -> int {
            int left = 0, right = nums.size() - 1;
            int ans = -1;
            // Binary search loop to narrow down range
            while (left <= right) {
                // Calculate midpoint to prevent potential overflow
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    ans = mid;
                    if (isFirst) right = mid - 1;
                    else left = mid + 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return ans;
        };

        return {findBound(true), findBound(false)};
    }
};