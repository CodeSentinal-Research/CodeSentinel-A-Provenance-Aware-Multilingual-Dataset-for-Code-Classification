#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<long long> heights(n);
        for (int i = 0; i < n; i++) std::cin >> heights[i];
        heights.push_back(0);
        // Monotonic stack to track visible elements
        std::stack<int> st;
        st.push(-1);
        long long max_area = 0;
        for (int i = 0; i <= n; i++) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                long long h = heights[st.top()];
                st.pop();
                long long w = i - st.top() - 1;
                max_area = std::max(max_area, h * w);
            }
            st.push(i);
        }
        std::cout << max_area << std::endl;
    }
    return 0;
}