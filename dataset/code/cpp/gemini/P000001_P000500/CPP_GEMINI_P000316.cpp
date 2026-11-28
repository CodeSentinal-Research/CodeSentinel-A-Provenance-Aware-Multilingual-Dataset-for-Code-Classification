#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) return false;
    std::unordered_map<char, char> st, ts;
    for (size_t i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];
        if (st.count(c1) && st[c1] != c2) return false;
        if (ts.count(c2) && ts[c2] != c1) return false;
        st[c1] = c2;
        ts[c2] = c1;
    }
    return true;
}

int main() {
    std::string s, t;
    if (std::cin >> s >> t) {
        std::cout << (isIsomorphic(s, t) ? "Yes" : "No") << std::endl;
    }
    return 0;
}