#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, diff;
    cin >> n >> diff;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> dp;
    int maxLen = 0;
    
    for (int num : nums) {
        dp[num] = dp[num - diff] + 1;
        maxLen = max(maxLen, dp[num]);
    }
    
    cout << maxLen << endl;
    return 0;
}
