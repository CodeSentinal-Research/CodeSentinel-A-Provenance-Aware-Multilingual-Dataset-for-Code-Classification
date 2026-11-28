#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_set<int> seen;
    int count = 0;
    
    // To ensure unique pairs, we can use a set of pairs or just count distinct values
    // Problem says "unique pairs". Usually means value pairs.
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        if (seen.count(nums[i] + k)) count++;
        if (k != 0 && seen.count(nums[i] - k)) count++;
        seen.insert(nums[i]);
    }
    
    cout << count << endl;
    return 0;
}
