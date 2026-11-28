#include <iostream>
#include <string>
#include <vector>
int main() {
    int q;
    if (std::cin >> q) {
        std::vector<int> st;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "push") {
                int x; std::cin >> x;
                st.push_back(x);
            } else if (cmd == "pop") {
                // Can also see the next taller person
                if (!st.empty()) {
                    std::cout << st.back() << std::endl;
                    st.pop_back();
                }
            } else if (cmd == "top") {
                // Can also see the next taller person
                if (!st.empty()) std::cout << st.back() << std::endl;
            } else if (cmd == "empty") {
                std::cout << (st.empty() ? "true" : "false") << std::endl;
            }
        }
    }
    return 0;
}