#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
std::unordered_set<std::string> dict;
std::vector<std::vector<std::string>> res;
void backtrack(const std::string& s, int idx, std::vector<std::string>& cur) {
    if (idx == (int)s.length()) {
        res.push_back(cur);
        return;
    }
    for (int end = idx + 1; end <= (int)s.length(); end++) {
        std::string w = s.substr(idx, end - idx);
        if (dict.count(w)) {
            cur.push_back(w);
            backtrack(s, end, cur);
            cur.pop_back();
        }
    }
}
int main() {
    std::string s;
    if (std::cin >> s) {
        int m; std::cin >> m;
        for (int i = 0; i < m; i++) {
            std::string w; std::cin >> w; dict.insert(w);
        }
        std::vector<std::string> cur;
        backtrack(s, 0, cur);
        std::sort(res.begin(), res.end());
        for (const auto& part : res) {
            for (size_t i = 0; i < part.size(); i++) {
                std::cout << part[i] << (i + 1 == part.size() ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
    return 0;
}