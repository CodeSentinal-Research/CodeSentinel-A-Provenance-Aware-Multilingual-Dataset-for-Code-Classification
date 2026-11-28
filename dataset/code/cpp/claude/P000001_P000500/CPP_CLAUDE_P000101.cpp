#include <vector>
#include <algorithm>
class Solution {
public:
    int findLargest(std::vector<int>& nums) {
        return *std::max_element(nums.begin(), nums.end());
    }
};
