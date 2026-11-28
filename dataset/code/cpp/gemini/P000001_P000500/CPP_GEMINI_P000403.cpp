#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> trains(n);
        for (int i = 0; i < n; i++) std::cin >> trains[i].first >> trains[i].second;
        std::string station;
        std::cin >> station;
        for (const auto& t : trains) if (t.second == station) std::cout << t.first << "\n";
    }
    return 0;
}