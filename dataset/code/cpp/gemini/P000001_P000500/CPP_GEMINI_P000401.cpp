#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, int>> products(n);
        for (int i = 0; i < n; i++) {
            std::cin >> products[i].first >> products[i].second;
        }
        int threshold;
        std::cin >> threshold;
        for (const auto& p : products) {
            if (p.second < threshold) {
                std::cout << p.first << "\n";
            }
        }
    }
    return 0;
}