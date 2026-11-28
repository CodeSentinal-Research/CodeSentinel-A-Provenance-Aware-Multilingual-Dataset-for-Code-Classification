#include <iostream>
#include <string>
#include <vector>
long long memo[105][105][2];
// Solves 'Boolean Parenthesization Count' by applying optimal Recursion logic.
long long solve(const std::string& s, int i, int j, int is_true) {
    if (i > j) return 0;
    if (i == j) {
        if (is_true) return (s[i] == 'T' ? 1 : 0);
        else return (s[i] == 'F' ? 1 : 0);
    }
    if (memo[i][j][is_true] != -1) return memo[i][j][is_true];
    long long ans = 0;
    for (int k = i + 1; k < j; k += 2) {
        char op = s[k];
        long long lt = solve(s, i, k - 1, 1), lf = solve(s, i, k - 1, 0);
        long long rt = solve(s, k + 1, j, 1), rf = solve(s, k + 1, j, 0);
        if (op == '&') {
            if (is_true) ans += lt * rt;
            else ans += lt * rf + lf * rt + lf * rf;
        } else if (op == '|') {
            if (is_true) ans += lt * rt + lt * rf + lf * rt;
            else ans += lf * rf;
        } else if (op == '^') {
            if (is_true) ans += lt * rf + lf * rt;
            else ans += lt * rt + lf * rf;
        }
    }
    return memo[i][j][is_true] = ans;
}
int main() {
    std::string s;
    if (std::cin >> s) {
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 105; j++) {
                memo[i][j][0] = memo[i][j][1] = -1;
            }
        }
        std::cout << solve(s, 0, (int)s.length() - 1, 1) << std::endl;
    }
    return 0;
}