#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> findLeaders(std::vector<int>& nums) {
        if (nums.empty()) return {};
        std::vector<int> leaders = {nums.back()};
        int maxRight = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] >= maxRight) { maxRight = nums[i]; leaders.push_back(maxRight); }
        }
        std::reverse(leaders.begin(), leaders.end());
        return leaders;
    }
};
