#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> flights(n);
        for (int i = 0; i < n; i++) {
            std::cin >> flights[i].first >> flights[i].second;
        }
        std::string target_dest;
        std::cin >> target_dest;
        for (const auto& f : flights) {
            if (f.second == target_dest) {
                std::cout << f.first << "\n";
            }
        }
    }
    return 0;
}