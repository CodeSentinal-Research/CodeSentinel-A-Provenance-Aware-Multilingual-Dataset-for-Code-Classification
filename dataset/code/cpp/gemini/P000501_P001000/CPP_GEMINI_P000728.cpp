#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
bool is_valid(const std::string& s) {
    int cnt = 0;
    for (char c : s) {
        if (c == '(') cnt++;
        else if (c == ')') {
            cnt--;
            if (cnt < 0) return false;
        }
    }
    return cnt == 0;
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::unordered_set<std::string> level = {s};
        while (!level.empty()) {
            std::vector<std::string> valid;
            for (const auto& item : level) {
                if (is_valid(item)) valid.push_back(item);
            }
            if (!valid.empty()) {
                std::sort(valid.begin(), valid.end());
                for (const auto& ans : valid) std::cout << ans << std::endl;
                return 0;
            }
            std::unordered_set<std::string> next_level;
            for (const auto& item : level) {
                for (size_t i = 0; i < item.length(); i++) {
                    if (item[i] == '(' || item[i] == ')') {
                        next_level.insert(item.substr(0, i) + item.substr(i + 1));
                    }
                }
            }
            level = next_level;
        }
        std::cout << std::endl;
    }
    return 0;
}