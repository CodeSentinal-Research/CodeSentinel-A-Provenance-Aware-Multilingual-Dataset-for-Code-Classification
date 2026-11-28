#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<int> st;
        st.push_back(-1);
        int max_len = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                st.push_back(i);
            } else {
                st.pop_back();
                if (st.empty()) {
                    st.push_back(i);
                } else {
                    max_len = std::max(max_len, i - st.back());
                }
            }
        }
        std::cout << max_len << std::endl;
    }
    return 0;
}