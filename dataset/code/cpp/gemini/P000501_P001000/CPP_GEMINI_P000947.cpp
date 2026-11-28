#include <vector>
#include <cstring>

class Solution {
    char memo[1 << 21];
    bool helper(int maxChoosable, int desiredTotal, int mask, int currentTotal) {
        if (memo[mask] != -1) return memo[mask];
        for (int i = 1; i <= maxChoosable; i++) {
            if ((mask & (1 << i)) == 0) {
                if (currentTotal + i >= desiredTotal || !helper(maxChoosable, desiredTotal, mask | (1 << i), currentTotal + i)) {
                    return memo[mask] = 1;
                }
            }
        }
        return memo[mask] = 0;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        int total = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (total < desiredTotal) return false;
        std::memset(memo, -1, sizeof(memo));
        return helper(maxChoosableInteger, desiredTotal, 0, 0);
    }
};