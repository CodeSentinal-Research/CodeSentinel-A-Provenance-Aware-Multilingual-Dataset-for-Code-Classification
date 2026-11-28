#include <iostream>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n), ans(n, -1);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        // Monotonic stack to track visible elements
        std::stack<int> st;
        for (int i = 0; i < 2 * n; i++) {
            int val = nums[i % n];
            // Pop smaller elements that are blocked from view
            while (!st.empty() && nums[st.top()] < val) {
                ans[st.top()] = val;
                st.pop();
            }
            if (i < n) st.push(i);
        }
        for (int i = 0; i < n; i++) std::cout << ans[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}