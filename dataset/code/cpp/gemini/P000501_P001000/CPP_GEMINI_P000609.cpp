#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> st;
        for (int i = 0; i < n; i++) {
            int x; std::cin >> x;
            st.push_back(x);
            int s = 0;
            for (int j = (int)st.size() - 1; j >= 0; j--) {
                s += st[j];
                if (s == 0) {
                    st.resize(j);
                    break;
                }
            }
        }
        for (size_t i = 0; i < st.size(); i++) {
            std::cout << st[i] << (i + 1 == st.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}