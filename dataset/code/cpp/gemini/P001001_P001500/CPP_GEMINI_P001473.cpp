#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (std::abs(sum - target) < std::abs(closestSum - target)) {
                    closestSum = sum;
                }
                if (sum < target) l++;
                else if (sum > target) r--;
                else return target;
            }
        }
        return closestSum;
    }
};