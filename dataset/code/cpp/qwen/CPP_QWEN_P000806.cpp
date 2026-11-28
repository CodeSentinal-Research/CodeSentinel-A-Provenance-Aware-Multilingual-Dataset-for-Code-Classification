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
    int currentSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += (nums[i] > 0 ? 1 : -1);
        if (prefixIndex.find(currentSum) != prefixIndex.end()) {
            maxLen = max(maxLen, i - prefixIndex[currentSum]);
        } else {
            prefixIndex[currentSum] = i;
        }
    }

    cout << maxLen << endl;
    return 0;
}
