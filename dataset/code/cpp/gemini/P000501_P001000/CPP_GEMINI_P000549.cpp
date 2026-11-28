#include <iostream>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> inp(n), out(n);
        for (int i = 0; i < n; i++) std::cin >> inp[i];
        for (int i = 0; i < n; i++) std::cin >> out[i];
        // Monotonic stack to track visible elements
        std::stack<int> st;
        int j = 0;
        for (int x : inp) {
            st.push(x);
            // Pop smaller elements that are blocked from view
            while (!st.empty() && j < n && st.top() == out[j]) {
                st.pop();
                j++;
            }
        }
        std::cout << (j == n ? "true" : "false") << std::endl;
    }
    return 0;
}