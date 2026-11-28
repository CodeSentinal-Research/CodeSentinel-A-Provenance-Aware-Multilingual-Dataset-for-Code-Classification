#include <vector>
#include <algorithm>

class Solution {
public:
    int minimizeMax(std::vector<int>& nums, int p) {
        if (p == 0) return 0;
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        int ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int count = 0;
            int i = 0;
            while (i < (int)nums.size() - 1) {
                if (nums[i + 1] - nums[i] <= mid) {
                    count++;
                    i += 2;
                } else {
                    i++;
                }
            }
            if (count >= p) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};