#include <iostream>
#include <string>
#include <vector>
#include <numeric>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> st;
        for (int i = 0; i < n; i++) {
            std::string op;
            std::cin >> op;
            if (op == "+") {
                st.push_back(st.back() + st[st.size() - 2]);
            } else if (op == "D") {
                st.push_back(st.back() * 2);
            } else if (op == "C") {
                st.pop_back();
            } else {
                st.push_back(std::stoi(op));
            }
        }
        int sum = 0;
        for (int v : st) sum += v;
        std::cout << sum << std::endl;
    }
    return 0;
}