#include <iostream>
#include <string>
#include <vector>
int main() {
    int cap, q;
    if (std::cin >> cap >> q) {
        std::vector<int> queue;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "enqueue") {
                int x; std::cin >> x;
                queue.push_back(x);
            } else if (cmd == "dequeue") {
                if (!queue.empty()) {
                    std::cout << queue.front() << std::endl;
                    queue.erase(queue.begin());
                }
            } else if (cmd == "front") {
                if (!queue.empty()) std::cout << queue.front() << std::endl;
            } else if (cmd == "isEmpty") {
                std::cout << (queue.empty() ? "true" : "false") << std::endl;
            }
        }
    }
    return 0;
}