#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int> &nums, int target, int start, vector<int> &path, vector<vector<int>> &res) {
    if (target < 0) return;
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        findCombinations(nums, target - nums[i], i, path, res);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(int target, vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(), nums.end());
    findCombinations(nums, target, 0, path, res);
    return res;
}

int main() {
    int N, target;
    cin >> N >> target;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> res = combinationSum(target, nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}