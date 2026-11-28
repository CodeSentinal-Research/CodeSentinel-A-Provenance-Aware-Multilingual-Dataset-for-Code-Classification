#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum2(vector<int> &candidates, int target, int start, vector<int> &current, vector<vector<int>> &result) {
    if (target < 0) {
        return;
    }
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }
        current.push_back(candidates[i]);
        combinationSum2(candidates, target - candidates[i], i + 1, current, result);
        current.pop_back();
    }
}

int main() {
    int N, Target;
    cin >> N >> Target;
    vector<int> candidates(N);
    for (int i = 0; i < N; i++) {
        cin >> candidates[i];
    }
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    combinationSum2(candidates, Target, 0, current, result);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}