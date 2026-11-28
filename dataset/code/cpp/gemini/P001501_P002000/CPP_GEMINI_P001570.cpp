#include <vector>
#include <algorithm>

class Solution {
public:
    int getMaxLen(std::vector<int>& nums) {
        int pos = 0, neg = 0, maxLen = 0;

        for (int x : nums) {
            if (x == 0) {
                pos = 0;
                neg = 0;
            } else if (x > 0) {
                pos++;
                neg = neg > 0 ? neg + 1 : 0;
            } else {
                int newPos = neg > 0 ? neg + 1 : 0;
                int newNeg = pos + 1;
                pos = newPos;
                neg = newNeg;
            }
            maxLen = std::max(maxLen, pos);
        }
        return maxLen;
    }
};