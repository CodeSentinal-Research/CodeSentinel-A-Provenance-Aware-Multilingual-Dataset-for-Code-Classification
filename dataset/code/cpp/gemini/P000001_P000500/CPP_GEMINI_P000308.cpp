#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, std::vector<int>> memo;

std::vector<int> diffWaysToCompute(std::string expr) {
    if (memo.count(expr)) return memo[expr];
    std::vector<int> res;
    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '+' || c == '-' || c == '*') {
            std::vector<int> left = diffWaysToCompute(expr.substr(0, i));
            std::vector<int> right = diffWaysToCompute(expr.substr(i + 1));
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
    return memo[expr] = res;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<int> res = diffWaysToCompute(s);
        for (int v : res) {
            std::cout << v << "\n";
        }
    }
    return 0;
}