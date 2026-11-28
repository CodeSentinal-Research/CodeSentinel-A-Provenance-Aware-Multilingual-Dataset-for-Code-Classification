#include <iostream>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        std::vector<int> st;
        for (int v : vals) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && st.back() < v) st.pop_back();
            st.push_back(v);
        }
        for (size_t i = 0; i < st.size(); i++) {
            std::cout << st[i] << (i + 1 == st.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}