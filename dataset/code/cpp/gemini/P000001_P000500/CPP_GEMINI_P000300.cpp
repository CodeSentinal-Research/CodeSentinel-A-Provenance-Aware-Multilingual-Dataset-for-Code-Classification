#include <iostream>
#include <string>
#include <vector>

void backtrack(const std::string& digits, int index, std::string current,
               const std::vector<std::string>& mapping, std::vector<std::string>& res) {
    if (index == (int)digits.length()) {
        res.push_back(current);
        return;
    }
    const std::string& letters = mapping[digits[index] - '0'];
    for (char c : letters) {
        backtrack(digits, index + 1, current + c, mapping, res);
    }
}

int main() {
    std::string digits;
    if (std::cin >> digits) {
        std::vector<std::string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> res;
        if (!digits.empty()) {
            backtrack(digits, 0, "", mapping, res);
        }
        for (const auto& s : res) {
            std::cout << s << "\n";
        }
    }
    return 0;
}