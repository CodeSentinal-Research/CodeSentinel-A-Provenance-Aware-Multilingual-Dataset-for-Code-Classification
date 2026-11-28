#include <vector>
#include <algorithm>

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxPair = 0;
        for (int i = 0; i < n / 2; i++) {
            maxPair = std::max(maxPair, nums[i] + nums[n - 1 - i]);
        }
        return maxPair;
    }
};