#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> findTriplet(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while (l < r) {
                int s = nums[i]+nums[l]+nums[r];
                if (s == target) return {nums[i],nums[l],nums[r]};
                else if (s < target) l++;
                else r--;
            }
        }
        return {};
    }
};
