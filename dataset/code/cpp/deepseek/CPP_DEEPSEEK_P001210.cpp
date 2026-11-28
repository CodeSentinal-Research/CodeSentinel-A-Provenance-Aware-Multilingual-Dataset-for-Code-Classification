#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(n);
    dp[0] = coins[0];

    for(int i = 1; i < n; i++) {
        dp[i] = max(coins[i], (i % 2 == 0 ? dp[i-1] : 0));
    }

    int maxValue = dp[n-1];
    cout << maxValue << endl;

    return 0;
}