#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        size_t insertPos = 0;
        for (int x : nums) {
            if (x != 0) nums[insertPos++] = x;
        }
        while (insertPos < nums.size()) {
            nums[insertPos++] = 0;
        }
    }
};