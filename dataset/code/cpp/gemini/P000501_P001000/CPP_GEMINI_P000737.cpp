#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
std::vector<int> diff_ways(const std::string& expr) {
    std::vector<int> res;
    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '+' || c == '-' || c == '*') {
            auto left = diff_ways(expr.substr(0, i));
            auto right = diff_ways(expr.substr(i + 1));
            for (int l : left) {
                for (int r : right) {
                    if (c == '+') res.push_back(l + r);
                    else if (c == '-') res.push_back(l - r);
                    else if (c == '*') res.push_back(l * r);
                }
            }
        }
    }
    if (res.empty()) res.push_back(std::stoi(expr));
    return res;
}
int main() {
    std::string expr;
    if (std::cin >> expr) {
        auto res = diff_ways(expr);
        std::sort(res.begin(), res.end());
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}