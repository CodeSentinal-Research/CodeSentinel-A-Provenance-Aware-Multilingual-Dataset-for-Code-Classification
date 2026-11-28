#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int solve(vector<int>& nums, int k) {
    int n = nums.size(), res = n + 1;
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i+1] = pref[i] + nums[i];
    deque<int> dq;
    for (int i = 0; i <= n; i++) {
        while (!dq.empty() && pref[i] - pref[dq.front()] >= k) {
            res = min(res, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && pref[dq.back()] >= pref[i]) dq.pop_back();
        dq.push_back(i);
    }
    return res > n ? -1 : res;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << solve(nums, k) << endl;
    return 0;
}
