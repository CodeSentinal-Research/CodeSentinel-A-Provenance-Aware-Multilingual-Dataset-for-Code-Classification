Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> activities(N);

    for (int i = 0; i < N; i++) {
        cin >> activities[i];
    }

    vector<int> dp(N);
    dp[0] = activities[0];
    dp[1] = max(activities[0], activities[1]);

    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + activities[i]);
    }

    cout << dp[N-1] << endl;

    return 0;
}

This code uses a dynamic programming approach to solve the problem. It initializes a vector `dp` of size `N` with `0`s. `dp[i]` represents the maximum happiness that can be achieved with `i` vacation days. 

The base cases are `dp[0] = activities[0]` and `dp[1] = max(activities[0], activities[1])`. 

For each day after the first two, the maximum happiness can be either the maximum happiness up to that day (`dp[i-1]`) or the maximum happiness up to the two previous days plus the happiness of the current day (`dp[i-2] + activities[i]`).

Finally, it prints `dp[N-1]`, which is the maximum total happiness, since `N-1` is the last day.