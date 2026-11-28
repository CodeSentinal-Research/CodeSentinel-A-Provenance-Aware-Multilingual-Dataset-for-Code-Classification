#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxLen = 0;
    int zeros = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        if (nums[right] == 0) zeros++;
        
        while (zeros > 1) {
            if (nums[left] == 0) zeros--;
            left++;
        }
        
        // Length of subarray with at most 1 zero
        // Since we must delete exactly one element, if the subarray is all 1s, we delete one 1, length reduces by 1.
        // If it has one 0, we delete that 0, length is count of 1s.
        // Effectively, we want longest subarray with at most 1 zero, then subtract 1 (for the deletion).
        // However, if the whole array is 1s, we must delete one, so result is n-1.
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    // If maxLen covers entire array and it's all 1s, we must delete one.
    // The logic "at most 1 zero" gives us the window.
    // If window has 0 zeros, we delete a 1 -> len-1.
    // If window has 1 zero, we delete the 0 -> len-1.
    // So always maxLen - 1.
    // But if array is empty? N>=1.
    
    if (maxLen == n) return n - 1; // Must delete one
    
    cout << maxLen - 1 << endl;
    return 0;
}
