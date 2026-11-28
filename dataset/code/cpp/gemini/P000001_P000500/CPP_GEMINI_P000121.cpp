#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        for (int x : nums) {
            if (count == 0) candidate = x;
            count += (x == candidate ? 1 : -1);
        }
        return candidate;
    }
};