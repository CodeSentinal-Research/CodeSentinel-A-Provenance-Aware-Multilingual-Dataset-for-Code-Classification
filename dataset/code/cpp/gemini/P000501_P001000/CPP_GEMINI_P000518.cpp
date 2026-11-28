#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
int main() {
    std::string s;
    if (std::cin >> s) {
        // Monotonic stack to track visible elements
        std::stack<int> st;
        st.push(-1);
        int max_len = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }
        std::cout << max_len << std::endl;
    }
    return 0;
}