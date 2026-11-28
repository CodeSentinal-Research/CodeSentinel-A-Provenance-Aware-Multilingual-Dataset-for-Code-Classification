#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    deque<int> dq;
    int maxScore = nums[0];
    dq.push_back(0);
    
    vector<int> dp(n, INT_MIN);
    dp[0] = nums[0];
    
    for (int i = 1; i < n; ++i) {
        // Remove indices out of window
        while (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }
        
        dp[i] = dp[dq.front()] + nums[i];
        maxScore = max(maxScore, dp[i]);
        
        // Maintain decreasing order in deque
        while (!dq.empty() && dp[dq.back()] <= dp[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    cout << dp[n-1] << endl;
    return 0;
}
