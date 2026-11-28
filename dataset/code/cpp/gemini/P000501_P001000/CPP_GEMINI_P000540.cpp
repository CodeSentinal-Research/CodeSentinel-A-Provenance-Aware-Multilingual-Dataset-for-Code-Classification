#include <iostream>
#include <string>
#include <list>
int main() {
    int q;
    if (std::cin >> q) {
        std::list<int> queue;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "enqueue") {
                int x; std::cin >> x;
                queue.push_back(x);
            } else if (cmd == "dequeue") {
                if (!queue.empty()) {
                    std::cout << queue.front() << std::endl;
                    queue.pop_front();
                }
            } else if (cmd == "front") {
                if (!queue.empty()) std::cout << queue.front() << std::endl;
            } else if (cmd == "size") {
                std::cout << queue.size() << std::endl;
            } else if (cmd == "isEmpty") {
                std::cout << (queue.empty() ? "true" : "false") << std::endl;
            }
        }
    }
    return 0;
}