#include <vector>
#include <algorithm>
class Solution {
public:
    int findMaxConsecutiveZeros(std::vector<int>& nums) {
        int best = 0, cur = 0;
        for (int x : nums) {
            cur = (x == 0) ? cur + 1 : 0;
            best = std::max(best, cur);
        }
        return best;
    }
};
