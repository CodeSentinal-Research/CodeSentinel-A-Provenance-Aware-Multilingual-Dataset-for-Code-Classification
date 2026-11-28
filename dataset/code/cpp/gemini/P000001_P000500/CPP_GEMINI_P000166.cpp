#include <vector>
#include <algorithm>

class Solution {
public:
    int minProductSubarray(std::vector<int>& nums) {
        int minProd = nums[0], maxProd = nums[0], ans = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int p1 = minProd * x, p2 = maxProd * x;
            minProd = std::min({x, p1, p2});
            maxProd = std::max({x, p1, p2});
            ans = std::min(ans, minProd);
        }
        return ans;
    }
};