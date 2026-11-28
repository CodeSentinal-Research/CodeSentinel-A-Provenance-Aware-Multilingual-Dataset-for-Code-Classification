#include <iostream>
#include <string>
#include <vector>

void backtrack(std::vector<std::string>& res, std::string current, int open, int close, int max) {
    if (current.length() == max * 2) {
        res.push_back(current);
        return;
    }
    if (open < max) {
        backtrack(res, current + "(", open + 1, close, max);
    }
    if (close < open) {
        backtrack(res, current + ")", open, close + 1, max);
    }
}

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> res;
        backtrack(res, "", 0, 0, n);
        for (const auto& s : res) {
            std::cout << s << "\n";
        }
    }
    return 0;
}