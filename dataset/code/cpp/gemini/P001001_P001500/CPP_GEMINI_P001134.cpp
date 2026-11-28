#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for (int n : nums) {
            int tmp = std::max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
};