#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;
        for (int n : nums) {
            if (n == 0) {
                curMin = 1;
                curMax = 1;
                res = std::max(res, 0);
                continue;
            }
            int tmp = curMax * n;
            curMax = std::max({n, n * curMax, n * curMin});
            curMin = std::min({n, tmp, n * curMin});
            res = std::max(res, curMax);
        }
        return res;
    }
};