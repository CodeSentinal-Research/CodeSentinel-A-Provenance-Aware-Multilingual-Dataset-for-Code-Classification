#include <vector>
#include <string>

class Solution {
    std::vector<std::string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(const std::string& digits, int idx, std::string cur, std::vector<std::string>& res) {
        if (idx == (int)digits.length()) {
            res.push_back(cur);
            return;
        }
        for (char c : phone[digits[idx] - '0']) {
            backtrack(digits, idx + 1, cur + c, res);
        }
    }
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};
        std::vector<std::string> res;
        backtrack(digits, 0, "", res);
        return res;
    }
};