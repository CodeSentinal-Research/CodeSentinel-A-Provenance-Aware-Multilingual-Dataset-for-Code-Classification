#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<long long> h(n);
        for (int i = 0; i < n; i++) std::cin >> h[i];
        std::vector<long long> left(n, 0), right(n, 0);
        // Monotonic stack to track visible elements
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && h[st.top()] >= h[i]) st.pop();
            left[i] = st.empty() ? h[i] * (i + 1) : left[st.top()] + h[i] * (i - st.top());
            st.push(i);
        }
        while (!st.empty()) st.pop();
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && h[st.top()] >= h[i]) st.pop();
            right[i] = st.empty() ? h[i] * (n - i) : right[st.top()] + h[i] * (st.top() - i);
            st.push(i);
        }
        long long max_sum = 0;
        for (int i = 0; i < n; i++) {
            max_sum = std::max(max_sum, left[i] + right[i] - h[i]);
        }
        std::cout << max_sum << std::endl;
    }
    return 0;
}