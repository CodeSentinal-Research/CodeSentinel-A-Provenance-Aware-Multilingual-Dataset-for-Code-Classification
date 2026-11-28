#include <iostream>
#include <string>
bool backtrack(const std::string& s, int idx, unsigned long long prev) {
    if (idx == (int)s.length()) return true;
    unsigned long long cur = 0;
    for (int i = idx; i < (int)s.length(); i++) {
        cur = cur * 10 + (s[i] - '0');
        if (prev != 0 && cur == prev - 1) {
            if (backtrack(s, i + 1, cur)) return true;
        } else if (prev != 0 && cur >= prev) {
            break;
        }
    }
    return false;
}
int main() {
    std::string s;
    if (std::cin >> s) {
        bool ok = false;
        unsigned long long first = 0;
        for (int i = 0; i < (int)s.length() - 1; i++) {
            first = first * 10 + (s[i] - '0');
            if (backtrack(s, i + 1, first)) { ok = true; break; }
        }
        std::cout << (ok ? "true" : "false") << std::endl;
    }
    return 0;
}