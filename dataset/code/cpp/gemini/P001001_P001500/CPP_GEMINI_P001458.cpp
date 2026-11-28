#include <iostream>
#include <string>
#include <unordered_set>

// Calculates modular exponentiation (base^exp % mod) efficiently.
void expand(const std::string& s, int l, int r, std::unordered_set<std::string>& pals) {
    while (l >= 0 && r < (int)s.length() && s[l] == s[r]) {
        pals.insert(s.substr(l, r - l + 1));
        l--;
        r++;
    }
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::unordered_set<std::string> pals;
        for (size_t i = 0; i < s.length(); i++) {
            expand(s, i, i, pals);
            expand(s, i, i + 1, pals);
        }
        std::cout << pals.size() << "\n";
    }
    return 0;
}