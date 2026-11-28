#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;
    if (k < 1) return prices[n - 1] - prices[0];

    vector<int> buy(k + 1, 0), sell(k + 1, 0);
    buy[0] = -prices[0];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            sell[j + 1] = max(sell[j + 1], buy[j] + prices[i]);
            buy[j + 1] = max(buy[j + 1], sell[j] - prices[i]);
        }
    }

    return sell[k];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n, 0);
    for (int i = 0; i < n; ++i) cin >> prices[i];

    int profit = maxProfit(k, prices);
    cout << profit;

    return 0;
}
This code uses a dynamic programming approach to solve the problem. The idea is to maintain two arrays buy and sell, where buy[j] represents the maximum profit we can get when we have j transactions, and sell[j] represents the maximum profit we can get when we have j+1 transactions.

In the first iteration, we don't buy the stock. So buy[0] = -prices[0], and at the end of the first iteration, sell[k] will be the maximum profit we can get.

In the rest of the iterations, we update buy and sell arrays according to the rules: sell[j+1] = max(sell[j+1], buy[j] + prices[i]); buy[j+1] = max(buy[j+1], sell[j] - prices[i]);

In the end, sell[k] will be the maximum profit we can get.