#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            res[st.top()] = nums[i % n];
            st.pop();
        }
        st.push(i % n);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> ans = solve(nums);
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
