#include <iostream>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> pushed(n), popped(n);
        for (int i = 0; i < n; i++) std::cin >> pushed[i];
        for (int i = 0; i < n; i++) std::cin >> popped[i];
        // Monotonic stack to track visible elements
        std::stack<int> st;
        int j = 0;
        for (int x : pushed) {
            st.push(x);
            // Pop smaller elements that are blocked from view
            while (!st.empty() && j < n && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        std::cout << (j == n ? "true" : "false") << std::endl;
    }
    return 0;
}