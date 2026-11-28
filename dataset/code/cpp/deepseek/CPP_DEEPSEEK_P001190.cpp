#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;
    vector<int> buy(n, 0), sell(n, 0), cooldown(n, 0);
    buy[0] = -prices[0];
    for (int i = 1; i < n; i++) {
        sell[i] = max(cooldown[i - 1], max(sell[i - 1], buy[i - 1] + prices[i]));
        buy[i] = max(cooldown[i - 1], buy[i - 1]) - prices[i];
        cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
    }
    return max(max(cooldown[n - 1], sell[n - 1]), buy[n - 1]);
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cout << maxProfit(prices) << endl;
    return 0;
}