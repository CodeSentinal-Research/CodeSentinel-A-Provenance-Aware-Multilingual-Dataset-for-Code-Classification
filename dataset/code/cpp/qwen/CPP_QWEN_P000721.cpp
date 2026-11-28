#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void findIncreasingSubsequences(vector<int>& nums, int start, vector<int>& current, set<vector<int>>& result) {
    if (current.size() >= 2) {
        result.insert(current);
    }
    
    for (int i = start; i < nums.size(); ++i) {
        if (current.empty() || nums[i] >= current.back()) {
            current.push_back(nums[i]);
            findIncreasingSubsequences(nums, i + 1, current, result);
            current.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    set<vector<int>> result;
    vector<int> current;
    findIncreasingSubsequences(nums, 0, current, result);
    
    for (const auto& seq : result) {
        for (size_t i = 0; i < seq.size(); ++i) {
            if (i > 0) cout << " ";
            cout << seq[i];
        }
        cout << endl;
    }
    return 0;
}
