Here's the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int splitArrayLargestSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(k+1, vector<int>(n+1));
    vector<int> sum(n+1);
    for(int i=0; i<n; ++i) sum[i+1] = sum[i] + nums[i];
    for(int i=0; i<=n; ++i) dp[1][i] = 0;
    for(int i=1; i<=k; ++i) dp[i][0] = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=k; ++j) {
            int m = sum[i] - sum[i-1];
            dp[j][i] = m;
            for(int p=1; p<i; ++p) {
                dp[j][i] = max(dp[j][i], max(dp[j-1][p] + m, sum[i] - sum[p]));
            }
        }
    }
    return dp[k][n];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; ++i) cin >> nums[i];
    cout << splitArrayLargestSum(nums, k) << endl;
    return 0;
}

This program uses a dynamic programming approach to solve the problem. The main idea is to use a 2D dp array to store the maximum sum for each subarray. The dp array dp[i][j] stores the maximum sum for subarrays of size i with at most j elements.

In the main function, the program first reads the size of the array n and the number of subarrays k. Then, it reads the elements of the array. Finally, it prints the minimum possible largest subarray sum by calling the function splitArrayLargestSum.