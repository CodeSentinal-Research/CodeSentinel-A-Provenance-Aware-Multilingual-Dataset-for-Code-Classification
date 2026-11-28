#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum < x) {
        cout << -1 << endl;
        return 0;
    }
    
    // Find longest subarray with sum = totalSum - x
    // Min operations = n - maxLen
    
    int target = totalSum - x;
    int maxLen = -1;
    int currentSum = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        currentSum += nums[right];
        while (currentSum > target && left <= right) {
            currentSum -= nums[left];
            left++;
        }
        if (currentSum == target) {
            maxLen = max(maxLen, right - left + 1);
        }
    }
    
    if (maxLen == -1) cout << -1 << endl;
    else cout << n - maxLen << endl;
    
    return 0;
}
