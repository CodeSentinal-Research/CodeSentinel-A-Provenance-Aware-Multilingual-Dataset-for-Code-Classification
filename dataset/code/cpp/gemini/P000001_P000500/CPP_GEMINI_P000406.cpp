#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> movies(n);
        for (int i = 0; i < n; i++) std::cin >> movies[i].first >> movies[i].second;
        std::string genre;
        std::cin >> genre;
        for (const auto& m : movies) if (m.second == genre) std::cout << m.first << "\n";
    }
    return 0;
}