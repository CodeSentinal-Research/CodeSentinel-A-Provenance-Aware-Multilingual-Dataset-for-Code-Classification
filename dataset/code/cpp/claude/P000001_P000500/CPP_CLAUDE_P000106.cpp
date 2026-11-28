#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> reverseArray(std::vector<int> nums) {
        std::reverse(nums.begin(), nums.end());
        return nums;
    }
};
