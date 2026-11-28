#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = index; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        generateSubsets(nums, i + 1, current, result);
        current.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(nums, 0, current, result);
    
    for (const auto& subset : result) {
        for (size_t i = 0; i < subset.size(); ++i) {
            if (i > 0) cout << " ";
            cout << subset[i];
        }
        cout << endl;
    }
    return 0;
}
