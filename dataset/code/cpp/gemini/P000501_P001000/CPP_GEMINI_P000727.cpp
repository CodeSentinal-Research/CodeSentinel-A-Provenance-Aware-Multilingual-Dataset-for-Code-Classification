#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
std::unordered_set<std::string> dict;
std::unordered_map<int, std::vector<std::string>> memo;
std::vector<std::string> backtrack(const std::string& s, int idx) {
    if (memo.count(idx)) return memo[idx];
    if (idx == (int)s.length()) return {""};
    std::vector<std::string> res;
    for (int end = idx + 1; end <= (int)s.length(); end++) {
        std::string w = s.substr(idx, end - idx);
        if (dict.count(w)) {
            auto sub = backtrack(s, end);
            for (const auto& sent : sub) {
                res.push_back(w + (sent.empty() ? "" : " ") + sent);
            }
        }
    }
    return memo[idx] = res;
}
int main() {
    std::string s;
    if (std::cin >> s) {
        int m; std::cin >> m;
        for (int i = 0; i < m; i++) {
            std::string w; std::cin >> w; dict.insert(w);
        }
        auto res = backtrack(s, 0);
        std::sort(res.begin(), res.end());
        for (const auto& sent : res) std::cout << sent << std::endl;
    }
    return 0;
}