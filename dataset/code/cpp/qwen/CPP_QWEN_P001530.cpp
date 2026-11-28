#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> lastSeen;
    int left = 0;
    long long maxSum = 0;
    long long currentSum = 0;
    
    for (int right = 0; right < n; ++right) {
        if (lastSeen.find(nums[right]) != lastSeen.end() && lastSeen[nums[right]] >= left) {
            // Remove elements from left to lastSeen[nums[right]]
            for (int i = left; i <= lastSeen[nums[right]]; ++i) {
                currentSum -= nums[i];
            }
            left = lastSeen[nums[right]] + 1;
        }
        
        lastSeen[nums[right]] = right;
        currentSum += nums[right];
        maxSum = max(maxSum, currentSum);
    }
    
    cout << maxSum << endl;
    return 0;
}
