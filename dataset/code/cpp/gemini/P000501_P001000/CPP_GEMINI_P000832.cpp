#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int splitArray(std::vector<int>& nums, int k) {
        int left = *std::max_element(nums.begin(), nums.end());
        int right = std::accumulate(nums.begin(), nums.end(), 0);
        int ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int pieces = 1, currSum = 0;
            for (int x : nums) {
                if (currSum + x > mid) {
                    pieces++;
                    currSum = x;
                } else {
                    currSum += x;
                }
            }
            if (pieces <= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};