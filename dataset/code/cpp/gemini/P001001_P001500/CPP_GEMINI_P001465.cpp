#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n);
        int l = 0, r = n - 1, pos = n - 1;

        // Binary search loop to narrow down range
        while (l <= r) {
            if (std::abs(nums[l]) > std::abs(nums[r])) {
                res[pos] = nums[l] * nums[l];
                l++;
            } else {
                res[pos] = nums[r] * nums[r];
                r--;
            }
            pos--;
        }
        return res;
    }
};