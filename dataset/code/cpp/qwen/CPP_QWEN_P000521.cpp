#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size(), passes = 0;
    vector<bool> removed(n, false);
    while (true) {
        bool changed = false;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (!removed[i]) {
                if (nums[i] > last) { last = nums[i]; removed[i] = true; changed = true; }
            }
        }
        if (!changed) break;
        passes++;
    }
    return passes;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << solve(nums) << endl;
    return 0;
}
