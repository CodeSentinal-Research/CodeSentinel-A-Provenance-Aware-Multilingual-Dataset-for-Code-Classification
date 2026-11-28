#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxLen = 0;
    int mask = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        // If current number shares bits with current window, shrink from left
        while ((mask & nums[right]) != 0) {
            mask ^= nums[left];
            left++;
        }
        mask |= nums[right];
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << maxLen << endl;
    return 0;
}
