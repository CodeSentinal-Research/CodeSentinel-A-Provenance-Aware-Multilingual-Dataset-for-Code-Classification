#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> segregateEvenOdd(std::vector<int> nums) {
        std::stable_partition(nums.begin(), nums.end(), [](int x){ return x%2==0; });
        return nums;
    }
};
