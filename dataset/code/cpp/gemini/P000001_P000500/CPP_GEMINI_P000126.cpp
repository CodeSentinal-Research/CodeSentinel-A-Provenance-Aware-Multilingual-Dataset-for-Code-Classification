#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if (std::abs(curSum - target) < std::abs(closest - target)) {
                    closest = curSum;
                }
                if (curSum < target) l++;
                else if (curSum > target) r--;
                else return target;
            }
        }
        return closest;
    }
};