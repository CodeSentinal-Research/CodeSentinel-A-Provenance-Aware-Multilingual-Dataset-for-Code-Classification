#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int l = 0, curSum = 0, ans = INT_MAX;

        for (size_t r = 0; r < nums.size(); r++) {
            curSum += nums[r];
            while (curSum >= target) {
                ans = std::min(ans, (int)(r - l + 1));
                curSum -= nums[l++];
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};