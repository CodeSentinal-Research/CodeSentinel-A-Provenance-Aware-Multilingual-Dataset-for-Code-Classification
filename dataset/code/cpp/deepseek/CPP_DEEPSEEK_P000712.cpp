Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, target, 0, path, res);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int target, int startIndex, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = s.combinationSum(candidates, target);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
This program uses a Depth-First Search (DFS) approach to solve the problem. It starts from the `startIndex` in each recursive call, and at each recursive call, it checks if the current number is smaller than the target. If it is, it adds the number to the path and recursively calls the function again. If the current number is larger than the target, it breaks the loop. If the target becomes 0, it means we have found a valid combination, so we add it to the result and return. After the recursive calls, it pops the last added number from the path to backtrack and tries the next number.