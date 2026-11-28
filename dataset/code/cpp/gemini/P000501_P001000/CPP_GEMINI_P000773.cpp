#include <iostream>
#include <string>
#include <map>
#include <climits>
std::map<int, std::map<long long, long long>> memo[105];
std::map<long long, long long> solve(const std::string& expr, int i, int j) {
    if (i == j) {
        return {{expr[i] - '0', 1}};
    }
    if (memo[i].count(j)) return memo[i][j];
    std::map<long long, long long> res;
    for (int k = i + 1; k < j; k += 2) {
        char op = expr[k];
        auto left = solve(expr, i, k - 1);
        auto right = solve(expr, k + 1, j);
        for (auto l : left) {
            for (auto r : right) {
                long long v = 0;
                if (op == '+') v = l.first + r.first;
                else if (op == '-') v = l.first - r.first;
                else if (op == '*') v = l.first * r.first;
                res[v] += l.second * r.second;
            }
        }
    }
    return memo[i][j] = res;
}
int main() {
    std::string expr;
    if (std::cin >> expr) {
        auto res = solve(expr, 0, (int)expr.length() - 1);
        std::cout << res.rbegin()->second << std::endl;
    }
    return 0;
}