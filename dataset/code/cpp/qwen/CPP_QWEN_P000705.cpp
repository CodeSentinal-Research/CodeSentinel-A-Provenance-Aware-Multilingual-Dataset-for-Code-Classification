#include <iostream>
#include <vector>
using namespace std;

void generateSubsequences(const vector<int>& nums, int index, vector<int>& current) {
    if (index == nums.size()) {
        for (size_t i = 0; i < current.size(); ++i) {
            if (i > 0) cout << " ";
            cout << current[i];
        }
        cout << endl;
        return;
    }
    // Exclude
    generateSubsequences(nums, index + 1, current);
    // Include
    current.push_back(nums[index]);
    generateSubsequences(nums, index + 1, current);
    current.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> current;
    generateSubsequences(nums, 0, current);
    return 0;
}
