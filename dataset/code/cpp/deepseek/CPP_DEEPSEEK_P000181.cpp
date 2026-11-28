#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, L, M;
    cin >> N >> L >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<int> dp(N, 0);
    dp[0] = nums[0];
    int maxSum = dp[0];

    for (int i = 1; i < L; i++) {
        dp[i] = max(dp[i - 1], 0) + nums[i];
        maxSum = max(maxSum, dp[i]);
    }

    for (int i = L; i < N; i++) {
        dp[i] = max(dp[i - 1], 0) + nums[i];
        maxSum = max(maxSum, dp[i]);
    }

    cout << maxSum << endl;

    return 0;
}