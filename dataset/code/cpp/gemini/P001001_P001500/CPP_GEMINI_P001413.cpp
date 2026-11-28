#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestUniqueNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int x : nums) map[x]++;

        int maxVal = -1;
        for (const auto& [x, cnt] : map) {
            if (cnt == 1) {
                maxVal = std::max(maxVal, x);
            }
        }
        return maxVal;
    }
};