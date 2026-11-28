#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &current, int start) {
    if (target < 0)
        return;
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;
        current.push_back(candidates[i]);
        combinationSum2(candidates, target - candidates[i], result, current, i + 1);
        current.pop_back();
    }
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    combinationSum2(candidates, target, result, current, 0);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
    return 0;
}