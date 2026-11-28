#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int l = 0;
        for (size_t r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) k--;
            if (k < 0) {
                if (nums[l] == 0) k++;
                l++;
            }
        }
        return nums.size() - l;
    }
};