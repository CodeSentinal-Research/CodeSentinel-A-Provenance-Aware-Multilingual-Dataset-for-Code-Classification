#include <vector>
#include <algorithm>
class Solution {
public:
    long long maxProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        long long o1 = (long long)nums[0] * nums[1];
        long long o2 = (long long)nums[n-2] * nums[n-1];
        return std::max(o1, o2);
    }
};
