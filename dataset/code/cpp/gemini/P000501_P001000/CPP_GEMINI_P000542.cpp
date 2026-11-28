#include <iostream>
#include <string>
#include <vector>
int main() {
    int q;
    if (std::cin >> q) {
        std::vector<int> queue;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "pushFront") {
                int x; std::cin >> x;
                queue.insert(queue.begin(), x);
            } else if (cmd == "pushMiddle") {
                int x; std::cin >> x;
                queue.insert(queue.begin() + queue.size() / 2, x);
            } else if (cmd == "pushBack") {
                int x; std::cin >> x;
                queue.push_back(x);
            } else if (cmd == "popFront") {
                if (queue.empty()) std::cout << -1 << std::endl;
                else {
                    std::cout << queue.front() << std::endl;
                    queue.erase(queue.begin());
                }
            } else if (cmd == "popMiddle") {
                if (queue.empty()) std::cout << -1 << std::endl;
                else {
                    // Calculate midpoint to prevent potential overflow
                    int mid = (queue.size() - 1) / 2;
                    std::cout << queue[mid] << std::endl;
                    queue.erase(queue.begin() + mid);
                }
            } else if (cmd == "popBack") {
                if (queue.empty()) std::cout << -1 << std::endl;
                else {
                    std::cout << queue.back() << std::endl;
                    queue.pop_back();
                }
            }
        }
    }
    return 0;
}