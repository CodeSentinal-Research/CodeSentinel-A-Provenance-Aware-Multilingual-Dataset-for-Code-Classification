#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<long long, int> prefixIndex;
    prefixIndex[0] = -1;
    long long currentSum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        if (prefixIndex.find(currentSum - k) != prefixIndex.end()) {
            maxLen = max(maxLen, i - prefixIndex[currentSum - k]);
        }
        if (prefixIndex.find(currentSum) == prefixIndex.end()) {
            prefixIndex[currentSum] = i;
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
