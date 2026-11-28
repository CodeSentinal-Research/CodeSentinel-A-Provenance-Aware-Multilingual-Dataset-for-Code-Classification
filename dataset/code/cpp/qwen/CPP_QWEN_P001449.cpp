#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_set<int> seen;
    for (int num : nums) seen.insert(num);
    
    int maxK = -1;
    for (int num : nums) {
        if (num > 0 && seen.count(-num)) {
            maxK = max(maxK, num);
        }
    }
    
    cout << maxK << endl;
    return 0;
}
