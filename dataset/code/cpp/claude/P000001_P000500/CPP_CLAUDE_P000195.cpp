#include <vector>
class Solution {
public:
    std::vector<int> cyclicRotate(std::vector<int> nums) {
        if (nums.empty()) return nums;
        int last = nums.back();
        for (int i=nums.size()-1;i>0;i--) nums[i]=nums[i-1];
        nums[0] = last;
        return nums;
    }
};
