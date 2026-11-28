#include <iostream>
#include <string>
#include <vector>
bool is_pal(const std::string& s, int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}
void pal_partition(const std::string& s, int start, std::vector<std::string>& cur) {
    if (start == (int)s.length()) {
        for (size_t i = 0; i < cur.size(); i++) {
            std::cout << cur[i] << (i + 1 == cur.size() ? "" : " ");
        }
        std::cout << std::endl;
        return;
    }
    for (int end = start; end < (int)s.length(); end++) {
        if (is_pal(s, start, end)) {
            cur.push_back(s.substr(start, end - start + 1));
            pal_partition(s, end + 1, cur);
            cur.pop_back();
        }
    }
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> cur;
        pal_partition(s, 0, cur);
    }
    return 0;
}