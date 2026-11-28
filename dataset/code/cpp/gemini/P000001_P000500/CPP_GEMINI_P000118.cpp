#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int idx = 0;
        for (int x : nums) {
            if (x != 0) nums[idx++] = x;
        }
        while (idx < (int)nums.size()) {
            nums[idx++] = 0;
        }
    }
};