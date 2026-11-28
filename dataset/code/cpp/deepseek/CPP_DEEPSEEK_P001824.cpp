#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums, int start, int end) {
    if (start > end) {
        return 1;
    }
    
    int count = 0;
    for (int i = start; i <= end; i++) {
        count += solve(nums, start, i - 1) * solve(nums, i + 1, end);
    }
    
    return count;
}

int numTrees(int n, int duplicateInsertionRule) {
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    
    if (duplicateInsertionRule == 1) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return solve(nums, 0, nums.size() - 1);
    } else if (duplicateInsertionRule == 2) {
        return solve(nums, 0, nums.size() - 1);
    } else {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return solve(nums, 0, nums.size() - 1);
    }
}

int main() {
    int n, duplicateInsertionRule;
    cin >> n >> duplicateInsertionRule;
    
    cout << numTrees(n, duplicateInsertionRule) << endl;
    
    return 0;
}