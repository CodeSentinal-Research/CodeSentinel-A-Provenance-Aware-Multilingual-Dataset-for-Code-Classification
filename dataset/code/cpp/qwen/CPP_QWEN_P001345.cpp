#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

void tugOfWar(vector<int>& nums, int index, vector<int>& set1, vector<int>& set2, int sum1, int sum2, int& minDiff) {
    if (index == nums.size()) {
        int diff = abs(sum1 - sum2);
        if (diff < minDiff) minDiff = diff;
        return;
    }
    
    // Pruning: if sizes differ by more than 1, stop? No, we assign all.
    // We need equal size sets.
    // This is complex. Simplified: just split into two halves of size N/2.
    
    if (set1.size() < nums.size() / 2) {
        set1.push_back(nums[index]);
        tugOfWar(nums, index + 1, set1, set2, sum1 + nums[index], sum2, minDiff);
        set1.pop_back();
    }
    
    if (set2.size() < nums.size() / 2) {
        set2.push_back(nums[index]);
        tugOfWar(nums, index + 1, set1, set2, sum1, sum2 + nums[index], minDiff);
        set2.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> set1, set2;
    int minDiff = INT_MAX;
    tugOfWar(nums, 0, set1, set2, 0, 0, minDiff);
    
    cout << minDiff << endl;
    return 0;
}
