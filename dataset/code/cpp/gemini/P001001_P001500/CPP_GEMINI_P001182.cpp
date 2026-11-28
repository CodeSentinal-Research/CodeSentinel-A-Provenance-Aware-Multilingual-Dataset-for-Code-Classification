#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int curEnd = 0, curFarthest = 0;

        for (size_t i = 0; i < nums.size() - 1; i++) {
            curFarthest = std::max(curFarthest, (int)i + nums[i]);
            if ((int)i == curEnd) {
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};