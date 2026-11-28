#include <iostream>
#include <string>
#include <vector>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<int> last_occ(26, 0);
        for (int i = 0; i < (int)s.length(); i++) last_occ[s[i] - 'a'] = i;
        std::vector<bool> seen(26, false);
        std::string st = "";
        for (int i = 0; i < (int)s.length(); i++) {
            int c = s[i] - 'a';
            if (!seen[c]) {
                // Pop smaller elements that are blocked from view
                while (!st.empty() && st.back() > s[i] && i < last_occ[st.back() - 'a']) {
                    seen[st.back() - 'a'] = false;
                    st.pop_back();
                }
                seen[c] = true;
                st.push_back(s[i]);
            }
        }
        std::cout << st << std::endl;
    }
    return 0;
}