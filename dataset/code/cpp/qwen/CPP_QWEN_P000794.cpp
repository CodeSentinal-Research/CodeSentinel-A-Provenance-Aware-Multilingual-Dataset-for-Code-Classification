#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> k;
    
    unordered_map<int, int> prefixSumIndex;
    prefixSumIndex[0] = -1;
    int currentSum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        if (prefixSumIndex.find(currentSum - k) != prefixSumIndex.end()) {
            maxLen = max(maxLen, i - prefixSumIndex[currentSum - k]);
        }
        if (prefixSumIndex.find(currentSum) == prefixSumIndex.end()) {
            prefixSumIndex[currentSum] = i;
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
