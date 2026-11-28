#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<long long, int> firstOccurrence;
    firstOccurrence[0] = -1;
    long long currentSum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        if (firstOccurrence.find(currentSum - k) != firstOccurrence.end()) {
            maxLen = max(maxLen, i - firstOccurrence[currentSum - k]);
        }
        if (firstOccurrence.find(currentSum) == firstOccurrence.end()) {
            firstOccurrence[currentSum] = i;
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
