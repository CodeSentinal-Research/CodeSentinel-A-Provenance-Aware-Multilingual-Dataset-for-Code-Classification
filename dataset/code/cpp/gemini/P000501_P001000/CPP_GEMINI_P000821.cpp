#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        // Binary search loop to narrow down range
        while (left < right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            // If current bit is set, multiply base into result
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};