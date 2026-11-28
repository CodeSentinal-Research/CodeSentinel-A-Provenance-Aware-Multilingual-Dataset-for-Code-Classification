#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubarray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    int longest = 1, curr = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            curr++;
        } else {
            longest = max(longest, curr);
            curr = 1;
        }
    }
    longest = max(longest, curr);
    return longest;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << longestIncreasingSubarray(nums);
    return 0;
}