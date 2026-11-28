#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<int> st = {0};
        for (char c : s) {
            if (c == '(') {
                st.push_back(0);
            } else {
                int v = st.back();
                st.pop_back();
                st.back() += std::max(2 * v, 1);
            }
        }
        std::cout << st[0] << std::endl;
    }
    return 0;
}