#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(vector<int>& nums, int l, int r, vector<vector<int>>& result) {
    if (l == r) {
        result.push_back(nums);
        return;
    }
    for (int i = l; i <= r; ++i) {
        swap(nums[l], nums[i]);
        generatePermutations(nums, l + 1, r, result);
        swap(nums[l], nums[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<vector<int>> result;
    generatePermutations(nums, 0, n - 1, result);
    
    sort(result.begin(), result.end());
    for (const auto& perm : result) {
        for (size_t i = 0; i < perm.size(); ++i) {
            if (i > 0) cout << " ";
            cout << perm[i];
        }
        cout << endl;
    }
    return 0;
}
