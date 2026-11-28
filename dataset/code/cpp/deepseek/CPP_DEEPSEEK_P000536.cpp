#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxScore(int n, vector<int>& nums, int k) {
    vector<int> dp(n, 0);
    dp[n - 1] = nums[n - 1];
    
    for (int i = n - 2; i >= 0; --i) {
        dp[i] = max(dp[i + 1], nums[i] + dp[min(i + k, n - 1)]);
    }
    
    return dp[0];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    
    int k;
    cin >> k;
    
    cout << maxScore(n, nums, k) << endl;
    
    return 0;
}
This code uses dynamic programming to solve the Jump Game VI problem. The main idea is to use a dp array to store the maximum score for each index, then update the score for each index in the range [i+1, min(i+k, n-1)]. The final score for index 0 is the maximum score.