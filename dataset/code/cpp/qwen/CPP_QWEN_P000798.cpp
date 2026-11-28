#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> prefixDiffIndex;
    prefixDiffIndex[0] = -1;
    int diff = 0;
    int maxLen = 0;
    
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) diff++;
        else diff--;
        
        if (prefixDiffIndex.find(diff) != prefixDiffIndex.end()) {
            maxLen = max(maxLen, i - prefixDiffIndex[diff]);
        } else {
            prefixDiffIndex[diff] = i;
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
