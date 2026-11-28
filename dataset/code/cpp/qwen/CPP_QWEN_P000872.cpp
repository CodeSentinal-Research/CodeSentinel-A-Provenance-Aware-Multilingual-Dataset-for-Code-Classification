#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxXor = 0;
    int mask = 0;
    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);
        int candidate = maxXor | (1 << i);
        bool found = false;
        for (int j = 0; j < n; ++j) {
            int prefix = nums[j] & mask;
            if (prefixCount.find(candidate ^ prefix) != prefixCount.end()) { // Need set
                found = true;
                break;
            }
        }
        // Simplified Trie approach is better but complex to code in one go.
        // Using brute force for small N or set approach for prefixes.
    }
    
    // Set approach for max XOR pair
    int maxVal = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            maxVal = max(maxVal, nums[i]^nums[j]);
        }
    }
    cout << maxVal << endl;
    return 0;
}
