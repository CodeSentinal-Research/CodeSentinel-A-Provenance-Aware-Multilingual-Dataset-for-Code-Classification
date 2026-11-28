#include <vector>
#include <numeric>
class Solution {
public:
    int findEquilibrium(std::vector<int>& nums) {
        long long total = std::accumulate(nums.begin(), nums.end(), 0LL), left = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            total -= nums[i];
            if (left == total) return i;
            left += nums[i];
        }
        return -1;
    }
};
