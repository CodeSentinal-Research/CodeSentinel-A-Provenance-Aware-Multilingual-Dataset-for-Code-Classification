#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> st;
        for (int i = 0; i < n; i++) {
            int ast;
            std::cin >> ast;
            bool alive = true;
            while (alive && ast < 0 && !st.empty() && st.back() > 0) {
                if (st.back() < -ast) {
                    st.pop_back();
                } else if (st.back() == -ast) {
                    st.pop_back();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) st.push_back(ast);
        }
        for (size_t i = 0; i < st.size(); i++) {
            std::cout << st[i] << (i + 1 == st.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}