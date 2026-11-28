#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
void case_perm(const std::string& s, int idx, std::string cur, std::vector<std::string>& res) {
    if (idx == (int)s.length()) {
        res.push_back(cur);
        return;
    }
    char ch = s[idx];
    if (std::isalpha(ch)) {
        case_perm(s, idx + 1, cur + (char)std::tolower(ch), res);
        case_perm(s, idx + 1, cur + (char)std::toupper(ch), res);
    } else {
        case_perm(s, idx + 1, cur + ch, res);
    }
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> res;
        case_perm(s, 0, "", res);
        std::sort(res.begin(), res.end());
        for (const auto& p : res) std::cout << p << std::endl;
    }
    return 0;
}