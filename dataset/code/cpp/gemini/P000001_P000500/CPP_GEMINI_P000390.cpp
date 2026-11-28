#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, double>> products(n);
        for (int i = 0; i < n; i++) {
            std::cin >> products[i].first >> products[i].second;
        }
        double min_p, max_p;
        std::cin >> min_p >> max_p;
        for (const auto& p : products) {
            if (p.second >= min_p && p.second <= max_p) {
                std::cout << p.first << "\n";
            }
        }
    }
    return 0;
}