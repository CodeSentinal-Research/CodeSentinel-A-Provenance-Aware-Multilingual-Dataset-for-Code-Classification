#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> prefixDiffCount;
    prefixDiffCount[0] = 1;
    int diff = 0; // count(1) - count(0)
    long long count = 0;
    
    for (int num : nums) {
        if (num == 1) diff++;
        else diff--;
        
        if (prefixDiffCount.find(diff) != prefixDiffCount.end()) {
            count += prefixDiffCount[diff];
        }
        prefixDiffCount[diff]++;
    }
    
    cout << count << endl;
    return 0;
}
