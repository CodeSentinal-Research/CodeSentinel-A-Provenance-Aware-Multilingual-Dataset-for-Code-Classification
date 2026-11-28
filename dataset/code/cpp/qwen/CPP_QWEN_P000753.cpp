#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findAllSubsequences(vector<int>& nums, int index, int target, int currentSum, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        if (currentSum == target) {
            result.push_back(current);
        }
        return;
    }
    
    // Include
    current.push_back(nums[index]);
    findAllSubsequences(nums, index + 1, target, currentSum + nums[index], current, result);
    current.pop_back();
    
    // Exclude
    findAllSubsequences(nums, index + 1, target, currentSum, current, result);
}

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> target;
    
    vector<vector<int>> result;
    vector<int> current;
    findAllSubsequences(nums, 0, target, 0, current, result);
    
    // Sort for lex order? Subsequences themselves might need sorting or the list of subsequences.
    // Usually "lexicographical order" for sets of sequences means sort the sequences.
    sort(result.begin(), result.end());
    
    for (const auto& seq : result) {
        for (size_t i = 0; i < seq.size(); ++i) {
            if (i > 0) cout << " ";
            cout << seq[i];
        }
        cout << endl;
    }
    return 0;
}
