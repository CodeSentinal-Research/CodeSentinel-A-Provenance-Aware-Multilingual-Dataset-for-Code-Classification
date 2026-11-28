#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    
    int minDiff = INT_MAX;
    for (int i = 1; i < n; ++i) {
        minDiff = min(minDiff, nums[i] - nums[i-1]);
    }
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] - nums[i-1] == minDiff) {
            cout << nums[i-1] << " " << nums[i] << endl;
        }
    }
    
    return 0;
}
