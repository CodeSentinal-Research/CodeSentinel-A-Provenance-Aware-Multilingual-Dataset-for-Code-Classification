#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n), st;
        for (int i = 0; i < n; i++) {
            std::cin >> vals[i];
            // Maintain monotonic stack property by popping smaller elements
            while (!st.empty() && st.back() < vals[i]) st.pop_back();
            st.push_back(vals[i]);
        }
        for (size_t i = 0; i < st.size(); i++) {
            std::cout << st[i] << (i + 1 == st.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}