#include <iostream>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> t(n), ans(n, 0);
        for (int i = 0; i < n; i++) std::cin >> t[i];
        // Monotonic stack to track visible elements
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && t[st.top()] < t[i]) {
                int prev = st.top(); st.pop();
                ans[prev] = i - prev;
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}