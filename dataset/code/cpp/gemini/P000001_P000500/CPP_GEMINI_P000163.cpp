#include <vector>
#include <algorithm>

class Solution {
public:
    bool find3Numbers(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if (curSum == target) return true;
                else if (curSum < target) l++;
                else r--;
            }
        }
        return false;
    }
};