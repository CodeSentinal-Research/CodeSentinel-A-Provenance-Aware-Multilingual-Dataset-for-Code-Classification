#include <iostream>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> p(n), ans(n);
        for (int i = 0; i < n; i++) { std::cin >> p[i]; ans[i] = p[i]; }
        // Monotonic stack to track visible elements
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && p[st.top()] >= p[i]) {
                ans[st.top()] -= p[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++) std::cout << ans[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}