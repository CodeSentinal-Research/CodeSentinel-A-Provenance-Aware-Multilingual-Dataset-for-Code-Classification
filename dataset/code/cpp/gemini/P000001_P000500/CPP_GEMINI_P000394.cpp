#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> products(n);
        for (int i = 0; i < n; i++) {
            std::cin >> products[i].first >> products[i].second;
        }
        std::string target_brand;
        std::cin >> target_brand;
        for (const auto& p : products) {
            if (p.second == target_brand) {
                std::cout << p.first << "\n";
            }
        }
    }
    return 0;
}