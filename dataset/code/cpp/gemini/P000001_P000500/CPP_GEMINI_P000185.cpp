#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        map[0] = -1;
        int curSum = 0, maxLen = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            curSum += (nums[i] == 1 ? 1 : -1);
            if (map.count(curSum)) {
                maxLen = std::max(maxLen, i - map[curSum]);
            } else {
                map[curSum] = i;
            }
        }
        return maxLen;
    }
};