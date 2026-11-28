Here is the C++ solution:

#include <iostream>
using namespace std;

int main() {
    int N, Amount;
    cin >> N >> Amount;
    int coins[N];
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    int dp[Amount + 1];
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = coins[i]; j <= Amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    cout << dp[Amount] << endl;
    return 0;
}

This code first reads in the number of coins and their values, and then it uses a dynamic programming approach to calculate the number of ways to form the target amount. The dp array stores the number of ways to form each amount up to the target amount. The outer loop iterates through each coin, and for each coin, the inner loop iterates through each amount up to the target amount. If the current amount - the value of the coin is greater than or equal to 0, the number of ways to form the current amount is incremented by the number of ways to form the amount - the value of the coin. The final result is stored in the dp array at the target amount.