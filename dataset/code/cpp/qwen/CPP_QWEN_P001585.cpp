#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    
    long long left = 0, right = 1e9;
    int maxFreq = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long ops = 0;
        int freq = 0;
        
        // Check if we can make 'freq' elements equal to nums[mid]
        // This binary search is on the value, not straightforward.
        // Standard solution: Binary search on answer (frequency) is hard.
        // Sliding window on sorted array is better.
    }
    
    // Sliding window approach
    long long leftPtr = 0;
    long long currentSum = 0;
    
    for (int rightPtr = 0; rightPtr < n; ++rightPtr) {
        currentSum += nums[rightPtr];
        
        while ((long long)nums[rightPtr] * (rightPtr - leftPtr + 1) - currentSum > k) {
            currentSum -= nums[leftPtr];
            leftPtr++;
        }
        
        maxFreq = max(maxFreq, rightPtr - leftPtr + 1);
    }
    
    cout << maxFreq << endl;
    return 0;
}
