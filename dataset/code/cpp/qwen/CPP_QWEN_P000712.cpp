#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > target) break;
        current.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], i, current, result); // i not i+1 because reuse allowed
        current.pop_back();
    }
}

int main() {
    int n, target;
    cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; ++i) cin >> candidates[i];
    cin >> target;
    
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    combinationSum(candidates, target, 0, current, result);
    
    for (const auto& comb : result) {
        for (size_t i = 0; i < comb.size(); ++i) {
            if (i > 0) cout << " ";
            cout << comb[i];
        }
        cout << endl;
    }
    return 0;
}
