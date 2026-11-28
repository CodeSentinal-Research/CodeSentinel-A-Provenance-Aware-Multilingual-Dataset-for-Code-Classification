#include <iostream>
#include <vector>
using namespace std;

bool isPalindromeRecursive(const vector<int>& nums, int left, int right) {
    if (left >= right) return true;
    if (nums[left] != nums[right]) return false;
    return isPalindromeRecursive(nums, left + 1, right - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    cout << (isPalindromeRecursive(nums, 0, n - 1) ? "true" : "false") << endl;
    return 0;
}
