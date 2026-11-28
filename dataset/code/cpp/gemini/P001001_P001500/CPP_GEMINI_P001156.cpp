#include <vector>

class Solution {
public:
    int superEggDrop(int k, int n) {
        std::vector<int> dp(k + 1, 0);
        int m = 0;
        while (dp[k] < n) {
            m++;
            for (int i = k; i > 0; i--) {
                // Update dynamic programming state transition
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }
        return m;
    }
};