#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solve(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> dp(n, -1e18);
    deque<int> dq;
    dp[0] = nums[0]; dq.push_back(0);
    for (int i = 1; i < n; i++) {
        while (!dq.empty() && dq.front() < i - k) dq.pop_front();
        dp[i] = dp[dq.front()] + nums[i];
        while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    return dp[n-1];
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << solve(nums, k) << endl;
    return 0;
}
