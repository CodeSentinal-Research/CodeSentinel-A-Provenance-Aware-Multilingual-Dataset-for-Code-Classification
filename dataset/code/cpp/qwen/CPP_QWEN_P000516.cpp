#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size(), mn = nums[0], mx = nums[n-1], l = 0, r = n - 1;
    for (int i = 0; i < n; i++) { if (nums[i] < mn) l = i; else mn = nums[i]; }
    for (int i = n - 1; i >= 0; i--) { if (nums[i] > mx) r = i; else mx = nums[i]; }
    return l < r ? r - l + 1 : 0;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << solve(nums) << endl;
    return 0;
}
