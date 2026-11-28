#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cutRod(vector<int> &prices, int N) {
    vector<int> dp(N + 1);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        int maxVal = -1;
        for (int j = 0; j < i; j++)
            maxVal = max(maxVal, prices[j] + dp[i - j - 1]);
        dp[i] = maxVal;
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;

    vector<int> prices(N);
    for (int i = 0; i < N; i++)
        cin >> prices[i];

    cout << cutRod(prices, N);

    return 0;
}
This C++ code will solve the rod cutting problem using a bottom-up approach. It initializes a dp table with zeros and then fills the table from bottom up. The cost of each length is either the maximum of the current length's price and the maximum obtainable from the remaining rod (i.e., prices[j] + dp[i - j - 1]), or just the maximum obtainable from the remaining rod (i.e., dp[i - j - 1]), if the current length's price is greater. The maximum obtainable revenue is the last element in the dp table.