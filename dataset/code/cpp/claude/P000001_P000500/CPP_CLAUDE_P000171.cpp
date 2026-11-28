#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> segregate01(std::vector<int>& nums) {
        std::stable_partition(nums.begin(), nums.end(), [](int x){ return x == 0; });
        return nums;
    }
};
