#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int l = 0, zeros = 0;
        for (size_t r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) zeros++;
            if (zeros > 1) {
                if (nums[l] == 0) zeros--;
                l++;
            }
        }
        return nums.size() - l - 1;
    }
};