#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};