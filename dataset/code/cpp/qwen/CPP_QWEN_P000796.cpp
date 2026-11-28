#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int n, p;
    cin >> n;
    vector<int> nums(n);
    long long totalSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        totalSum += nums[i];
    }
    cin >> p;
    
    if (totalSum % p == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int targetRem = totalSum % p;
    unordered_map<int, int> prefixModIndex;
    prefixModIndex[0] = -1;
    long long currentSum = 0;
    int minLen = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        int currentMod = currentSum % p;
        if (currentMod < 0) currentMod += p;
        
        int neededMod = (currentMod - targetRem + p) % p;
        
        if (prefixModIndex.find(neededMod) != prefixModIndex.end()) {
            minLen = min(minLen, i - prefixModIndex[neededMod]);
        }
        prefixModIndex[currentMod] = i;
    }
    
    if (minLen == INT_MAX || minLen == n) cout << -1 << endl;
    else cout << minLen << endl;
    
    return 0;
}
