#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums1(n);
        for (int i = 0; i < n; i++) std::cin >> nums1[i];
        int m;
        std::cin >> m;
        std::vector<int> nums2(m);
        for (int i = 0; i < m; i++) std::cin >> nums2[i];
        std::unordered_map<int, int> nxt;
        // Monotonic stack to track visible elements
        std::stack<int> st;
        for (int x : nums2) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && st.top() < x) {
                nxt[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        while (!st.empty()) {
            nxt[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < n; i++) {
            std::cout << nxt[nums1[i]] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}