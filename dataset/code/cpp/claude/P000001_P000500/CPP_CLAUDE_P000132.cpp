#include <vector>
#include <numeric>
class Solution {
public:
    int equilibriumIndex(std::vector<int>& nums) {
        long long total = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long leftSum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            total -= nums[i];
            if (leftSum == total) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
