#include <iostream>
#include <queue>
#include <string>

int main() {
    int q;
    if (std::cin >> q) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        while (q--) {
            std::string op;
            std::cin >> op;
            if (op == "INSERT") {
                int val;
                std::cin >> val;
                pq.push(val);
            } else if (op == "EXTRACT_MIN") {
                if (pq.empty()) std::cout << "EMPTY\n";
                else {
                    std::cout << pq.top() << "\n";
                    pq.pop();
                }
            } else if (op == "PEEK") {
                if (pq.empty()) std::cout << "EMPTY\n";
                else std::cout << pq.top() << "\n";
            }
        }
    }
    return 0;
}