#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
    int q;
    if (std::cin >> q) {
        std::vector<int> st, min_st;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "push") {
                int x; std::cin >> x;
                st.push_back(x);
                min_st.push_back(min_st.empty() ? x : std::min(x, min_st.back()));
            } else if (cmd == "pop") {
                // Can also see the next taller person
                if (!st.empty()) { st.pop_back(); min_st.pop_back(); }
            } else if (cmd == "top") {
                // Can also see the next taller person
                if (!st.empty()) std::cout << st.back() << std::endl;
            } else if (cmd == "getMin") {
                if (!min_st.empty()) std::cout << min_st.back() << std::endl;
            }
        }
    }
    return 0;
}