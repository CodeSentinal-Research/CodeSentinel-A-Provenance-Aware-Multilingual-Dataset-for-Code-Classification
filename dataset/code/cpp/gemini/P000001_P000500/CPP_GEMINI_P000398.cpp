#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> vehicles(n);
        for (int i = 0; i < n; i++) {
            std::cin >> vehicles[i].first >> vehicles[i].second;
        }
        std::string target_manuf;
        std::cin >> target_manuf;
        for (const auto& v : vehicles) {
            if (v.second == target_manuf) {
                std::cout << v.first << "\n";
            }
        }
    }
    return 0;
}