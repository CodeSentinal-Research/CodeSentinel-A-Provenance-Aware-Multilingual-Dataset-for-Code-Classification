#include <iostream>
#include <vector>
using namespace std;

bool findSubsequence(vector<int>& nums, int index, int target, int currentSum, vector<int>& current) {
    if (index == nums.size()) {
        return currentSum == target;
    }
    
    // Include
    current.push_back(nums[index]);
    if (findSubsequence(nums, index + 1, target, currentSum + nums[index], current)) return true;
    current.pop_back();
    
    // Exclude
    if (findSubsequence(nums, index + 1, target, currentSum, current)) return true;
    
    return false;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> target;
    
    vector<int> current;
    if (findSubsequence(nums, 0, target, 0, current)) {
        for (size_t i = 0; i < current.size(); ++i) {
            if (i > 0) cout << " ";
            cout << current[i];
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
