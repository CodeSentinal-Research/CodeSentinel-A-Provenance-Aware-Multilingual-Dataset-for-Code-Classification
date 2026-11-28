#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    unordered_map<int, int> prefixIndex;
    prefixIndex[0] = -1;
    int diff = 0; // count(even) - count(odd)
    int maxLen = 0;

    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == 0) diff++;
        else diff--;
        
        if (prefixIndex.find(diff) != prefixIndex.end()) {
            maxLen = max(maxLen, i - prefixIndex[diff]);
        } else {
            prefixIndex[diff] = i;
        }
    }

    cout << maxLen << endl;
    return 0;
}
