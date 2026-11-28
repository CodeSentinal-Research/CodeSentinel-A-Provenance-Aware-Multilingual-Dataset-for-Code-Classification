#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> seen;
        seen[0] = -1;
        int curSum = 0, maxLen = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            curSum += (nums[i] == 1 ? 1 : -1);
            if (seen.count(curSum)) {
                maxLen = std::max(maxLen, (int)i - seen[curSum]);
            } else {
                seen[curSum] = i;
            }
        }
        return maxLen;
    }
};