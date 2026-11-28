#include <vector>

class Solution {
public:
    // Performs search to locate target element within the given collection.
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};