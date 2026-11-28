#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int count = 0;
    bool isIncreasing = true;
    
    for (int i = 1; i < k; ++i) {
        if (nums[i] <= nums[i-1]) {
            isIncreasing = false;
            break;
        }
    }
    if (isIncreasing) count++;
    
    for (int i = k; i < n; ++i) {
        // Check if new window is increasing
        // Optimization: track if previous window was increasing and boundary conditions
        // Simple re-check for clarity
        isIncreasing = true;
        for (int j = i - k + 1; j < i; ++j) { // Check internal pairs
             if (nums[j+1] <= nums[j]) {
                 isIncreasing = false;
                 break;
             }
        }
        // Also check connection if we slid? No, window is fresh.
        // Actually, just check the whole window.
        for (int j = i - k + 1; j < i - k + 1 + k - 1; ++j) {
             if (nums[j+1] <= nums[j]) {
                 isIncreasing = false;
                 break;
             }
        }
        
        if (isIncreasing) count++;
    }
    
    cout << count << endl;
    return 0;
}
