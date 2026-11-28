#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> buildings(n);
    for (int i = 0; i < n; i++) {
        cin >> buildings[i];
    }

    int bricks, ladders;
    cin >> bricks >> ladders;

    vector<int> dp(n + 1, 0);
    dp[0] = buildings[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1], buildings[i]);
        if (i < bricks) {
            dp[i] = max(dp[i], buildings[i] + dp[i - bricks]);
        }
        if (i < ladders) {
            dp[i] = max(dp[i], buildings[i] + dp[i - ladders]);
        }
    }

    cout << dp[n - 1] << "\n";

    return 0;
}