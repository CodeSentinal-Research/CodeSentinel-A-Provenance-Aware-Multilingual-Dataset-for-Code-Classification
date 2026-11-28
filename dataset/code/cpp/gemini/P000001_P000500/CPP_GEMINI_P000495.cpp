#include <iostream>
#include <vector>
#include <stack>
int main() {
    int q;
    if (std::cin >> q) {
        std::stack<std::pair<int, int>> st;
        while (q--) {
            int price;
            std::cin >> price;
            int span = 1;
            // Pop smaller elements that are blocked from view
            while (!st.empty() && st.top().first <= price) {
                span += st.top().second;
                st.pop();
            }
            st.push({price, span});
            std::cout << span << std::endl;
        }
    }
    return 0;
}