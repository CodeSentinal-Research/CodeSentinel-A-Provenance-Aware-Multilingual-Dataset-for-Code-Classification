Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> activities(N);

    for (int i = 0; i < N; i++) {
        activities[i].resize(3);
        for (int& j : activities[i]) {
            cin >> j;
        }
    }

    vector<int> dp(N + 1, 0);
    for (int i = 0; i < N; i++) {
        dp[i + 1] = max({dp[i], dp[i - 1], dp[i - 2] + activities[i][0]});
        dp[i + 1] = max(dp[i + 1], dp[i - 1] + activities[i][1]);
        dp[i + 1] = max(dp[i + 1], dp[i - 2] + activities[i][2]);
    }

    cout << dp[N] << '\n';

    return 0;
}

This code uses dynamic programming to solve the problem. It initializes a dynamic programming (DP) array `dp` where `dp[i]` represents the maximum merit points obtainable with `i` training days. The DP array is filled iteratively using the optimal substructure property. The optimal substructure property is that if we have a problem `p` with solution `s`, and if the solution of `p` is a solution for `s`, then we can use `s` to solve `p`. In this case, if `i` is 0 or 1, the maximum of all possible activities is the maximum of the current activity and the maximum of the two activities before it. The maximum of the current activity and the maximum of the two activities before it is the maximum of the maximum of all possible activities. This is done by adding the merit points of the current activity to the maximum of the maximum of all possible activities and the maximum of the maximum of all possible activities two days before and the maximum of the maximum of all possible activities one day before.