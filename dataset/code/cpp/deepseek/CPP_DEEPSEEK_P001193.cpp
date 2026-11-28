#include <iostream>
using namespace std;

int rob(int *nums, int start, int end) {
    int *dp = new int[end - start + 1];
    dp[0] = nums[start];
    if(end == start) return dp[0];
    dp[1] = max(nums[start], nums[start + 1]);
    for(int i = 2; i <= end - start; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
    }
    int res = dp[end - start];
    delete[] dp;
    return res;
}

int main() {
    int N;
    cin >> N;
    int *nums = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int res = rob(nums, 0, N - 1);
    cout << res << endl;
    delete[] nums;
    return 0;
}