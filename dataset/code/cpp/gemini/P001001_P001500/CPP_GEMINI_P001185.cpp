#include <vector>
#include <algorithm>

class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        int maxVal = *std::max_element(nums.begin(), nums.end());
        std::vector<int> count(maxVal + 1, 0);
        for (int x : nums) count[x] += x;

        int rob1 = 0, rob2 = 0;
        for (int v : count) {
            int tmp = std::max(rob1 + v, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
};