#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> orders(n);
        for (int i = 0; i < n; i++) {
            std::cin >> orders[i].first >> orders[i].second;
        }
        std::string target_status;
        std::cin >> target_status;
        for (const auto& o : orders) {
            if (o.second == target_status) {
                std::cout << o.first << "\n";
            }
        }
    }
    return 0;
}