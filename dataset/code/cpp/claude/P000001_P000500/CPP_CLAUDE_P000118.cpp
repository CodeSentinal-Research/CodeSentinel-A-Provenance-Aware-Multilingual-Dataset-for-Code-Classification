#include <vector>
class Solution {
public:
    std::vector<int> moveZeroes(std::vector<int> nums) {
        int k = 0;
        for (int x : nums) if (x != 0) nums[k++] = x;
        while (k < (int)nums.size()) nums[k++] = 0;
        return nums;
    }
};
