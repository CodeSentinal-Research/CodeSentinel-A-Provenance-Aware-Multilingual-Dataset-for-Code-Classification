#include <vector>
#include <algorithm>

class Solution {
public:
    int lenOfLongDecSubArr(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLen = 1, curLen = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                curLen++;
                maxLen = std::max(maxLen, curLen);
            } else {
                curLen = 1;
            }
        }
        return maxLen;
    }
};