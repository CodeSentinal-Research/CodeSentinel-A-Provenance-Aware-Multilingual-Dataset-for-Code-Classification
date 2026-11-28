#include <vector>
#include <numeric>
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n + 1) / 2;
        return expected - std::accumulate(nums.begin(), nums.end(), 0);
    }
};
