#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int curSum = 0, maxLen = -1, l = 0;
        for (size_t r = 0; r < nums.size(); r++) {
            curSum += nums[r];
            while (curSum > target && l <= (int)r) {
                curSum -= nums[l++];
            }
            if (curSum == target) {
                maxLen = std::max(maxLen, (int)r - l + 1);
            }
        }
        return maxLen == -1 ? -1 : (int)nums.size() - maxLen;
    }
};