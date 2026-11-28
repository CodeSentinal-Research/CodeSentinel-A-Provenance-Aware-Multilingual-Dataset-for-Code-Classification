#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s, p;
    if (std::cin >> s >> p) {
        if (s.length() < p.length()) {
            std::cout << 0 << "\n";
            return 0;
        }
        std::vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) pCount[c - 'a']++;

        int ans = 0, pLen = p.length();
        for (size_t i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            if (i >= (size_t)pLen) sCount[s[i - pLen] - 'a']--;
            if (pCount == sCount) ans++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}