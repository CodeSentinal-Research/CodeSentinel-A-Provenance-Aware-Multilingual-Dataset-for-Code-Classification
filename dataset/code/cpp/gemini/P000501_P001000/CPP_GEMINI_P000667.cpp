#include <iostream>
#include <string>
#include <deque>
int main() {
    int q;
    if (std::cin >> q) {
        std::deque<int> dq;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "insertFront") {
                int v; std::cin >> v; dq.push_front(v);
            } else if (cmd == "insertLast") {
                int v; std::cin >> v; dq.push_back(v);
            } else if (cmd == "deleteFront") {
                if (!dq.empty()) dq.pop_front();
            } else if (cmd == "deleteLast") {
                if (!dq.empty()) dq.pop_back();
            } else if (cmd == "getFront") {
                std::cout << (dq.empty() ? -1 : dq.front()) << std::endl;
            } else if (cmd == "getRear") {
                std::cout << (dq.empty() ? -1 : dq.back()) << std::endl;
            } else if (cmd == "isEmpty") {
                std::cout << (dq.empty() ? "true" : "false") << std::endl;
            } else if (cmd == "size") {
                std::cout << dq.size() << std::endl;
            }
        }
    }
    return 0;
}