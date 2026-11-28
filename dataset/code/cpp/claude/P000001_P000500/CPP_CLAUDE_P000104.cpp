#include <vector>
#include <numeric>
class Solution {
public:
    double arrayAverage(std::vector<int>& nums) {
        return (double)std::accumulate(nums.begin(), nums.end(), 0LL) / nums.size();
    }
};
