#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void add_ops(const std::string& num, long long target, int idx, std::string cur_expr, long long cur_val, long long prev_op, std::vector<std::string>& res) {
    if (idx == (int)num.length()) {
        if (cur_val == target) res.push_back(cur_expr);
        return;
    }
    for (int i = idx; i < (int)num.length(); i++) {
        if (i > idx && num[idx] == '0') break;
        std::string part = num.substr(idx, i - idx + 1);
        long long v = std::stoll(part);
        if (idx == 0) {
            add_ops(num, target, i + 1, part, v, v, res);
        } else {
            add_ops(num, target, i + 1, cur_expr + "+" + part, cur_val + v, v, res);
            add_ops(num, target, i + 1, cur_expr + "-" + part, cur_val - v, -v, res);
            add_ops(num, target, i + 1, cur_expr + "*" + part, cur_val - prev_op + prev_op * v, prev_op * v, res);
        }
    }
}
int main() {
    std::string num; long long target;
    if (std::cin >> num >> target) {
        std::vector<std::string> res;
        add_ops(num, target, 0, "", 0, 0, res);
        std::sort(res.begin(), res.end());
        for (const auto& s : res) std::cout << s << std::endl;
    }
    return 0;
}