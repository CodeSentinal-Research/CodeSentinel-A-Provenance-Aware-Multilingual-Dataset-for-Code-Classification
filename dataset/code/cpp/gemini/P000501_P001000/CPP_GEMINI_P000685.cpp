#include <iostream>
#include <string>
bool is_pal_rec(const std::string& s, int l, int r) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return is_pal_rec(s, l + 1, r - 1);
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << (is_pal_rec(s, 0, (int)s.length() - 1) ? "true" : "false") << std::endl;
    }
    return 0;
}