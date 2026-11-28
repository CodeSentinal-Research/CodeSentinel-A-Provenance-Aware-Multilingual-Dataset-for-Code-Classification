#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        int cash = 0, hold = -prices[0];
        for (size_t i = 1; i < prices.size(); i++) {
            cash = std::max(cash, hold + prices[i] - fee);
            hold = std::max(hold, cash - prices[i]);
        }
        return cash;
    }
};