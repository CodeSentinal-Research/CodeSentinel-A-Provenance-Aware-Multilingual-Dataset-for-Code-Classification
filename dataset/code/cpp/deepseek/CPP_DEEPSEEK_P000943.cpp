Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int stoneGameII(vector<int> &piles) {
    int n = piles.size();
    vector<int> dp(n + 1, 0);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += piles[i];
        dp[i + 1] = sum;
    }

    int total = 0;
    for (int i = 1; i <= n; ++i) {
        total += piles[n - i];
        dp[i] = max(dp[i], total + sum - dp[n - i + 1]);
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];
    }

    cout << stoneGameII(piles) << endl;

    return 0;
}

In this code, we use a dynamic programming approach to solve the problem. The state of the problem is defined by the sum of stones in piles. For each stone pile, we calculate the maximum total sum we can get when we have taken the current stone pile and then the sum of remaining piles.