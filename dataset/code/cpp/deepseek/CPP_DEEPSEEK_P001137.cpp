#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minCoins(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (int i = 0; i <= amount; i++) {
        if (dp[i] != -1) {
            for (int j = 0; j < coins.size(); j++) {
                if (i + coins[j] <= amount && dp[i + coins[j]] == -1) {
                    dp[i + coins[j]] = dp[i] + 1;
                }
            }
        }
    }

    return dp[amount] == -1 ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << minCoins(coins, amount);
    return 0;
}