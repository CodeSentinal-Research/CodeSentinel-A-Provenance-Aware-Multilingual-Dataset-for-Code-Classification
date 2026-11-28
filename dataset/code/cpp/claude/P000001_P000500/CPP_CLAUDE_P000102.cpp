#include <vector>
#include <algorithm>
class Solution {
public:
    int findSmallest(std::vector<int>& nums) {
        return *std::min_element(nums.begin(), nums.end());
    }
};
