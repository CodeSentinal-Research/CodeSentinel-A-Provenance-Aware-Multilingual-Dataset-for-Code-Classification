#include <vector>
#include <algorithm>

class Solution {
public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int usedBits = 0, l = 0, maxLen = 0;

        for (size_t r = 0; r < nums.size(); r++) {
            while ((usedBits & nums[r]) != 0) {
                usedBits ^= nums[l++];
            }
            usedBits |= nums[r];
            maxLen = std::max(maxLen, (int)(r - l + 1));
        }
        return maxLen;
    }
};