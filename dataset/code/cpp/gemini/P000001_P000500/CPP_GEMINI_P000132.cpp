#include <vector>
#include <numeric>

class Solution {
public:
    int findEquilibriumIndex(std::vector<int>& nums) {
        long long totalSum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long leftSum = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};