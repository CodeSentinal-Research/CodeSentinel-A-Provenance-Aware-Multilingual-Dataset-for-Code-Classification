#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s, vector<string>& dict) {
        sort(dict.begin(), dict.end());
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, dict, path, result);
        return result;
    }

private:
    void backtrack(int start, string s, vector<string>& dict, vector<string>& path, vector<vector<string>>& result) {
        if (start >= s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            string substring = s.substr(start, i - start + 1);
            if (binary_search(dict.begin(), dict.end(), substring)) {
                path.push_back(substring);
                backtrack(i + 1, s, dict, path, result);
                path.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    string s = "pineapplepenin";
    vector<string> dict = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<vector<string>> result = solution.partition(s, dict);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}