#include <iostream>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> h(n), ans(n, 0);
        for (int i = 0; i < n; i++) std::cin >> h[i];
        // Monotonic stack to track visible elements
        std::stack<int> st;
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            // Pop smaller elements that are blocked from view
            while (!st.empty() && st.top() < h[i]) {
                st.pop();
                count++;
            }
            // Can also see the next taller person
            if (!st.empty()) count++;
            ans[i] = count;
            st.push(h[i]);
        }
        for (int i = 0; i < n; i++) std::cout << ans[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}