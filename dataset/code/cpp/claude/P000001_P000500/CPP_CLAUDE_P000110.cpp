#include <vector>
#include <algorithm>
class Solution {
public:
    int countFrequency(std::vector<int>& nums, int target) {
        return std::count(nums.begin(), nums.end(), target);
    }
};
