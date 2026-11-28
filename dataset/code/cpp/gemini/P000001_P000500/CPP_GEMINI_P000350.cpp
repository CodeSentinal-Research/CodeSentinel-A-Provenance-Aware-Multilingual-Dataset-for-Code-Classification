#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    int k;
    if (std::cin >> s >> k) {
        std::vector<std::pair<char, int>> st;
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                if (++st.back().second == k) {
                    st.pop_back();
                }
            } else {
                st.push_back({c, 1});
            }
        }
        std::string res = "";
        for (const auto& p : st) {
            res.append(p.second, p.first);
        }
        std::cout << res << std::endl;
    }
    return 0;
}