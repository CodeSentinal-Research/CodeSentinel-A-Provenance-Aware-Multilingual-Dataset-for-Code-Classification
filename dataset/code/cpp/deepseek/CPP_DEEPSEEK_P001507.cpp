Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> up(n), down(n);
    up[0] = down[0] = 1;
    int max_len = 1;

    for (int i = 1; i < n; ++i) {
        up[i] = down[i] = 1;
        if (nums[i] > nums[i-1]) {
            up[i] = down[i-1] + 1;
        } else if (nums[i] < nums[i-1]) {
            down[i] = up[i-1] + 1;
        } else {
            down[i] = up[i] = down[i-1] + 1;
        }
        max_len = max(max_len, max(down[i], up[i]));
    }

    return max_len;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << solve(nums) << endl;
    return 0;
}

This code uses dynamic programming to solve the problem. It keeps track of the length of the longest up and down sequences for each element. For each element, it checks if the element is greater than or less than the previous element. If it's greater, it extends the up sequence by 1, otherwise it extends the down sequence by 1. It also updates the maximum length found so far. The final maximum length is the maximum of all up and down sequences.