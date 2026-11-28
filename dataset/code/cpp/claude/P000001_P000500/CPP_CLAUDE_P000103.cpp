#include <vector>
#include <numeric>
class Solution {
public:
    long long arraySum(std::vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0LL);
    }
};
