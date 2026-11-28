#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if ((int)i > maxReach) return false;
            maxReach = std::max(maxReach, (int)i + nums[i]);
        }
        return true;
    }
};