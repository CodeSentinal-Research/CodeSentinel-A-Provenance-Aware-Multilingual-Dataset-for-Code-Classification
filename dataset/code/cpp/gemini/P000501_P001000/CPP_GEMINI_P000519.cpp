#include <iostream>
#include <string>
#include <stack>
int main() {
    int q;
    if (std::cin >> q) {
        // Monotonic stack to track visible elements
        std::stack<int> s1, s2;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "push") {
                int x; std::cin >> x;
                s1.push(x);
            } else if (cmd == "pop") {
                if (s2.empty()) {
                    while (!s1.empty()) { s2.push(s1.top()); s1.pop(); }
                }
                if (!s2.empty()) { std::cout << s2.top() << std::endl; s2.pop(); }
            } else if (cmd == "peek") {
                if (s2.empty()) {
                    while (!s1.empty()) { s2.push(s1.top()); s1.pop(); }
                }
                if (!s2.empty()) std::cout << s2.top() << std::endl;
            } else if (cmd == "empty") {
                std::cout << (s1.empty() && s2.empty() ? "true" : "false") << std::endl;
            }
        }
    }
    return 0;
}