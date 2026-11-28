#include <vector>
#include <algorithm>
class Solution {
public:
    long long minProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        long long a = (long long)nums[0] * nums[1];
        long long b = (long long)nums[0] * nums[n-1];
        long long c = (long long)nums[n-2] * nums[n-1];
        return std::min({a, b, c});
    }
};
