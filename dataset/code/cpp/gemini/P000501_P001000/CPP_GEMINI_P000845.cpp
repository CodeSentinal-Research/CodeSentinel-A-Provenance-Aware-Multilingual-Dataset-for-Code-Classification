#include <vector>
#include <algorithm>

class Solution {
public:
    int minCapability(std::vector<int>& nums, int k) {
        int left = *std::min_element(nums.begin(), nums.end());
        int right = *std::max_element(nums.begin(), nums.end());
        int ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int count = 0;
            int i = 0;
            while (i < (int)nums.size()) {
                if (nums[i] <= mid) {
                    count++;
                    i += 2;
                } else {
                    i++;
                }
            }
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};