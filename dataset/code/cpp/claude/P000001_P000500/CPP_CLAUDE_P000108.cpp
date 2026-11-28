#include <vector>
#include <algorithm>
class Solution {
public:
    bool isSortedDesc(std::vector<int>& nums) {
        return std::is_sorted(nums.begin(), nums.end(), std::greater<int>());
    }
};
