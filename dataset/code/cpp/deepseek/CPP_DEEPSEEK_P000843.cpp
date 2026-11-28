#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findMinMaxDifference(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    
    int minDiff = nums[nums.size() - 1] - nums[0];
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size() && p > 1; j++) {
            if (nums[j] - nums[i] < minDiff) {
                minDiff = nums[j] - nums[i];
            }
        }
    }
    
    return minDiff;
}

int main() {
    int n, p;
    cin >> n >> p;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << findMinMaxDifference(nums, p);
    
    return 0;
}