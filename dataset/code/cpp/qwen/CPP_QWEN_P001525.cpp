#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // Transform: even -> 1, odd -> -1? No.
    // We want equal count.
    // Map even to 1, odd to -1. Find longest subarray with sum 0.
    
    unordered_map<int, int> prefixIndex;
    prefixIndex[0] = -1;
    int currentSum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum += (nums[i] % 2 == 0 ? 1 : -1);
        if (prefixIndex.find(currentSum) != prefixIndex.end()) {
            maxLen = max(maxLen, i - prefixIndex[currentSum]);
        } else {
            prefixIndex[currentSum] = i;
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
