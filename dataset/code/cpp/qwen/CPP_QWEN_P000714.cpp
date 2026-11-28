#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetSums(vector<int>& nums, int index, int currentSum, vector<int>& sums) {
    if (index == nums.size()) {
        sums.push_back(currentSum);
        return;
    }
    // Exclude
    subsetSums(nums, index + 1, currentSum, sums);
    // Include
    subsetSums(nums, index + 1, currentSum + nums[index], sums);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> sums;
    subsetSums(nums, 0, 0, sums);
    sort(sums.begin(), sums.end());
    
    for (size_t i = 0; i < sums.size(); ++i) {
        if (i > 0) cout << " ";
        cout << sums[i];
    }
    cout << endl;
    return 0;
}
