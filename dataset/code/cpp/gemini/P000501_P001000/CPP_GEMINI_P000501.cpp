#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> st = {""};
        for (char c : s) {
            if (c == '(') {
                st.push_back("");
            } else if (c == ')') {
                std::string top = st.back();
                st.pop_back();
                std::reverse(top.begin(), top.end());
                st.back() += top;
            } else {
                st.back() += c;
            }
        }
        std::cout << st[0] << std::endl;
    }
    return 0;
}