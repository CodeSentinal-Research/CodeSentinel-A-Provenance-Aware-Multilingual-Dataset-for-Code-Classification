#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        int n = prices.size();
        if (k >= n / 2) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
            }
            return res;
        }

        std::vector<int> buy(k + 1, INT_MAX);
        std::vector<int> profit(k + 1, 0);

        for (int p : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = std::min(buy[i], p - profit[i - 1]);
                profit[i] = std::max(profit[i], p - buy[i]);
            }
        }
        return profit[k];
    }
};