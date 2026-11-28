#include <iostream>
#include <string>
#include <vector>
#include <set>
std::vector<std::string> diff_ways(const std::string& expr) {
    std::vector<std::string> res;
    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '+' || c == '-' || c == '*') {
            auto left = diff_ways(expr.substr(0, i));
            auto right = diff_ways(expr.substr(i + 1));
            for (const auto& l : left) {
                for (const auto& r : right) {
                    res.push_back("(" + l + c + r + ")");
                }
            }
        }
    }
    if (res.empty()) res.push_back(expr);
    return res;
}
int main() {
    std::string expr;
    if (std::cin >> expr) {
        auto res = diff_ways(expr);
        std::set<std::string> unique_res(res.begin(), res.end());
        for (const auto& s : unique_res) std::cout << s << std::endl;
    }
    return 0;
}