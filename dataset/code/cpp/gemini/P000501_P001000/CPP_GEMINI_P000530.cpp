#include <iostream>
#include <string>
#include <vector>
int main() {
    int cap, q;
    if (std::cin >> cap >> q) {
        std::vector<int> q_vec;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "enQueue") {
                int x; std::cin >> x;
                if ((int)q_vec.size() < cap) {
                    q_vec.push_back(x);
                    std::cout << "true\n";
                } else {
                    std::cout << "false\n";
                }
            } else if (cmd == "deQueue") {
                if (!q_vec.empty()) {
                    q_vec.erase(q_vec.begin());
                    std::cout << "true\n";
                } else {
                    std::cout << "false\n";
                }
            } else if (cmd == "Front") {
                std::cout << (q_vec.empty() ? -1 : q_vec.front()) << std::endl;
            } else if (cmd == "Rear") {
                std::cout << (q_vec.empty() ? -1 : q_vec.back()) << std::endl;
            } else if (cmd == "isEmpty") {
                std::cout << (q_vec.empty() ? "true" : "false") << std::endl;
            } else if (cmd == "isFull") {
                std::cout << ((int)q_vec.size() == cap ? "true" : "false") << std::endl;
            }
        }
    }
    return 0;
}