#include <iostream>
#include <string>
#include <vector>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<char> st;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if (!st.empty() && st.back() == '?') {
                st.pop_back(); // '?'
                char first = st.back(); st.pop_back();
                st.pop_back(); // ':'
                char second = st.back(); st.pop_back();
                st.push_back(c == 'T' ? first : second);
            } else {
                st.push_back(c);
            }
        }
        std::cout << st[0] << std::endl;
    }
    return 0;
}