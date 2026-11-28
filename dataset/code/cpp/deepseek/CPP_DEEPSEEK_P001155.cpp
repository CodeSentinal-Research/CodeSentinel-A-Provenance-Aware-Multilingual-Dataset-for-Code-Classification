#include <iostream>
#include <vector>
using namespace std;

int maxCoins(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0] * nums[0];
    vector<int> dp(n+2, 0);
    dp[0] = 0;
    dp[n+1] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i], nums[i-1] * nums[i] * nums[i+1]);
        dp[i+1] = max(dp[i+1], dp[i]);
    }
    return max(dp[1], dp[n] + nums[0] * nums[n-1]);
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    cout << maxCoins(nums) << endl;
    return 0;
}