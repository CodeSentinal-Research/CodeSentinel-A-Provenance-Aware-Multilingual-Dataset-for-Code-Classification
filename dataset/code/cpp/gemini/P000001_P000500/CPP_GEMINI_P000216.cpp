#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, int> first, last, count;
        int degree = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            int x = nums[i];
            if (!first.count(x)) first[x] = i;
            last[x] = i;
            degree = std::max(degree, ++count[x]);
        }

        int minLen = nums.size();
        for (auto& [x, cnt] : count) {
            if (cnt == degree) {
                minLen = std::min(minLen, last[x] - first[x] + 1);
            }
        }
        return minLen;
    }
};