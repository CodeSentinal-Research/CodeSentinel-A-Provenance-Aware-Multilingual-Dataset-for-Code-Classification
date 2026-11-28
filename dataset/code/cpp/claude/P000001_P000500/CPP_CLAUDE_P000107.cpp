#include <vector>
#include <algorithm>
class Solution {
public:
    bool isSortedAsc(std::vector<int>& nums) {
        return std::is_sorted(nums.begin(), nums.end());
    }
};
