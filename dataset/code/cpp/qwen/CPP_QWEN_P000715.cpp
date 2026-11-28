#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetsWithDup(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i-1]) continue;
        current.push_back(nums[i]);
        subsetsWithDup(nums, i + 1, current, result);
        current.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    subsetsWithDup(nums, 0, current, result);
    
    for (const auto& subset : result) {
        for (size_t i = 0; i < subset.size(); ++i) {
            if (i > 0) cout << " ";
            cout << subset[i];
        }
        cout << endl;
    }
    return 0;
}
