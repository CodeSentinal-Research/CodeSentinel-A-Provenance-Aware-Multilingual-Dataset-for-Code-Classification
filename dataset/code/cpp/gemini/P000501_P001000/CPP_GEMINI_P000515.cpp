#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
struct Car { double p, s; };
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<Car> cars(n);
        for (int i = 0; i < n; i++) std::cin >> cars[i].p >> cars[i].s;
        std::vector<double> ans(n, -1.0);
        // Monotonic stack to track visible elements
        std::stack<int> st;
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty()) {
                int j = st.top();
                if (cars[i].s <= cars[j].s || (ans[j] > 0 && (cars[j].p - cars[i].p) / (cars[i].s - cars[j].s) >= ans[j])) {
                    st.pop();
                } else {
                    break;
                }
            }
            // Can also see the next taller person
            if (!st.empty()) {
                int j = st.top();
                ans[i] = (cars[j].p - cars[i].p) / (cars[i].s - cars[j].s);
            }
            st.push(i);
        }
        std::cout << std::fixed << std::setprecision(5);
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}