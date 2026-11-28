#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> stk;

    for (int i = 0; i < n * 2; i++) {
        while (!stk.empty() && (nums[stk.top()] < nums[i % n])) {
            res[stk.top()] = nums[i % n];
            stk.pop();
        }
        stk.push(i % n);
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> res = nextGreaterElements(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    return 0;
}