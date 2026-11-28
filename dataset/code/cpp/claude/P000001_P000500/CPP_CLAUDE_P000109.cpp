#include <vector>
class Solution {
public:
    int linearSearch(std::vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] == target) return i;
        return -1;
    }
};
