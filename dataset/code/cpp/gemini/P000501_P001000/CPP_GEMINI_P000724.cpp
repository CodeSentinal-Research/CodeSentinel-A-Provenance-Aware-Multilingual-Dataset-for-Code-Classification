#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int max_len = 0;
void backtrack(const std::vector<std::pair<int, int>>& masks, int idx, int cur_m, int cur_len) {
    max_len = std::max(max_len, cur_len);
    for (size_t i = idx; i < masks.size(); i++) {
        if (!(cur_m & masks[i].first)) {
            backtrack(masks, i + 1, cur_m | masks[i].first, cur_len + masks[i].second);
        }
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<int, int>> masks;
        for (int i = 0; i < n; i++) {
            std::string s; std::cin >> s;
            int m = 0; bool dup = false;
            for (char c : s) {
                int b = 1 << (c - 'a');
                if (m & b) { dup = true; break; }
                m |= b;
            }
            if (!dup) masks.push_back({m, (int)s.length()});
        }
        backtrack(masks, 0, 0, 0);
        std::cout << max_len << std::endl;
    }
    return 0;
}