#include <vector>
#include <algorithm>
#include <cmath>
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if (std::abs(s - target) < std::abs(closest - target)) closest = s;
                if (s < target) l++;
                else if (s > target) r--;
                else return s;
            }
        }
        return closest;
    }
};
