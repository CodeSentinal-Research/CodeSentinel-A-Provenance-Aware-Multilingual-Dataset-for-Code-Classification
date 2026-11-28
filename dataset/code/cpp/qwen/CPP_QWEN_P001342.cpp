#include <iostream>
#include <vector>
using namespace std;

void findIncreasingSubsequences(vector<int>& nums, int start, int k, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i < nums.size(); ++i) {
        if (current.empty() || nums[i] > current.back()) {
            current.push_back(nums[i]);
            findIncreasingSubsequences(nums, i + 1, k, current, result);
            current.pop_back();
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<vector<int>> result;
    vector<int> current;
    findIncreasingSubsequences(nums, 0, k, current, result);
    
    for (const auto& seq : result) {
        for (size_t i = 0; i < seq.size(); ++i) {
            if (i > 0) cout << " ";
            cout << seq[i];
        }
        cout << endl;
    }
    return 0;
}
