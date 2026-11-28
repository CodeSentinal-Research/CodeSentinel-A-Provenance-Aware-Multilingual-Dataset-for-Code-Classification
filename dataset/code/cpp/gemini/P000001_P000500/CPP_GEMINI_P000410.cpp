#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> products(n);
        for (int i = 0; i < n; i++) std::cin >> products[i];
        std::string suffix;
        std::cin >> suffix;
        for (const auto& p : products) {
            if (p.length() >= suffix.length() && p.rfind(suffix) == p.length() - suffix.length()) {
                std::cout << p << "\n";
            }
        }
    }
    return 0;
}