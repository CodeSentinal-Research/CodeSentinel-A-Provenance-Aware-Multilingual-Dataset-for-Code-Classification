#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> hours(n);
    for (int i = 0; i < n; ++i) cin >> hours[i];
    
    // Transform: >8 -> 1, <=8 -> -1. Find longest subarray with sum > 0.
    vector<int> transformed(n);
    for (int i = 0; i < n; ++i) {
        transformed[i] = (hours[i] > 8) ? 1 : -1;
    }
    
    unordered_map<int, int> prefixIndex;
    prefixIndex[0] = -1;
    int currentSum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum += transformed[i];
        if (prefixIndex.find(currentSum - 1) != prefixIndex.end()) {
             maxLen = max(maxLen, i - prefixIndex[currentSum - 1]);
        }
        // Store earliest index for each sum
        if (prefixIndex.find(currentSum) == prefixIndex.end()) {
            prefixIndex[currentSum] = i;
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
