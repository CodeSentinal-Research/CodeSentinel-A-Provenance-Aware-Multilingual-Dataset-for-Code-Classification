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
    
    unordered_map<int, int> prefixModIndex;
    prefixModIndex[0] = -1;
    int currentSum = 0;
    
    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        int mod = currentSum % k;
        if (mod < 0) mod += k;
        
        if (prefixModIndex.find(mod) != prefixModIndex.end()) {
            if (i - prefixModIndex[mod] >= 2) {
                cout << "true" << endl;
                return 0;
            }
        } else {
            prefixModIndex[mod] = i;
        }
    }
    
    cout << "false" << endl;
    return 0;
}
