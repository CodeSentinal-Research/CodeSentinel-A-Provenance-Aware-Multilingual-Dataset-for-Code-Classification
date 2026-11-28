#include <vector>
#include <algorithm>

class Solution {
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = 1, cur = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
                ans = std::max(ans, cur);
            } else {
                cur = 1;
            }
        }
        return ans;
    }
};