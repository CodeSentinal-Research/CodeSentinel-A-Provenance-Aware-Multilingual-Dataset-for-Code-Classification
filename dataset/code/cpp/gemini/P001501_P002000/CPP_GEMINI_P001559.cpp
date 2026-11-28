#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, l = 0;

        for (size_t r = 0; r < nums.size(); r++) {
            prod *= nums[r];
            while (prod >= k) {
                prod /= nums[l++];
            }
            ans += r - l + 1;
        }
        return ans;
    }
};