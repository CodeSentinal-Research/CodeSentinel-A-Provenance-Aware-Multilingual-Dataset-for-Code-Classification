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
    
    unordered_map<int, int> prefixModCount;
    prefixModCount[0] = 1;
    int currentSum = 0;
    long long count = 0;
    
    for (int num : nums) {
        currentSum += num;
        int mod = currentSum % k;
        if (mod < 0) mod += k;
        
        if (prefixModCount.find(mod) != prefixModCount.end()) {
            count += prefixModCount[mod];
        }
        prefixModCount[mod]++;
    }
    
    cout << count << endl;
    return 0;
}
