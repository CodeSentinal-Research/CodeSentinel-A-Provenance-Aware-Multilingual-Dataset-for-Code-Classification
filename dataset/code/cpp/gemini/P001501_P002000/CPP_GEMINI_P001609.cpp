#include <vector>
#include <numeric>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int left = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (left == total - left - nums[i]) return i;
            left += nums[i];
        }
        return -1;
    }
};