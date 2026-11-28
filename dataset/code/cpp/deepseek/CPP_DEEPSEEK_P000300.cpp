#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    unordered_map<string, string> mapping = {
        {"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"},
        {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        backtrack(0, digits, "", result);
        return result;
    }

private:
    void backtrack(int index, string &digits, string path, vector<string> &result) {
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = mapping[digits[index]];
        for (char c : letters) {
            path.push_back(c);
            backtrack(index + 1, digits, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution solution;
    string digits = "23";
    vector<string> result = solution.letterCombinations(digits);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}