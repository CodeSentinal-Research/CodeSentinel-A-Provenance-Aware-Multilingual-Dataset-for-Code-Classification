#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int rev(int x) {
    int res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> cnt;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = nums[i] + rev(nums[i]);
        res += cnt[sum];
        cnt[sum]++;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << countNicePairs(nums) << endl;
    return 0;
}
This C++ code defines a function `rev()` to reverse a given integer `x`. The `countNicePairs()` function counts the number of nice pairs in the given array `nums`. It uses a hash map `cnt` to count the frequency of the sum of each pair in `nums`. For each pair `nums[i]` + `rev(nums[i])`, it increases the count of the pair sum in `cnt`. Finally, it returns the total count of nice pairs.