#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size(), res = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            res = max(res, i - st.top());
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << solve(nums) << endl;
    return 0;
}
