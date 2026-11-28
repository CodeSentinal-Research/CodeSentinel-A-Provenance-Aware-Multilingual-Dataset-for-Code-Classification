#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> generateIncreasingSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(), nums.end());
    generateSubsequences(0, nums, path, res);
    return res;
}

void generateSubsequences(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
    if (path.size() >= 2) {
        res.push_back(path);
    }

    for (int i = start; i < nums.size(); i++) {
        if (path.empty() || nums[i] < path.back()) {
            path.push_back(nums[i]);
            generateSubsequences(i + 1, nums, path, res);
            path.pop_back();
        }
    }
}

int main() {
    vector<int> nums = {1, 3, 1, 2, 4};
    auto res = generateIncreasingSubsequences(nums);
    for (auto& vec : res) {
        for (int num : vec) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}