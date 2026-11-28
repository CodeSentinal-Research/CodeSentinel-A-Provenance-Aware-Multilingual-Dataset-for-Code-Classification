#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // Transform 0 to -1 to use prefix sum for equal counts
    unordered_map<int, int> prefixIndex;
    prefixIndex[0] = -1;
    int currentSum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum += (nums[i] == 0 ? -1 : 1);
        if (prefixIndex.find(currentSum) != prefixIndex.end()) {
            maxLen = max(maxLen, i - prefixIndex[currentSum]);
        } else {
            prefixIndex[currentSum] = i;
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
