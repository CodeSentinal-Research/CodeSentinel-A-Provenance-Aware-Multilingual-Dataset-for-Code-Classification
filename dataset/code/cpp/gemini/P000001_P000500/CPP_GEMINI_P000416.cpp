#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, int>> vehicles(n);
        for (int i = 0; i < n; i++) std::cin >> vehicles[i].first >> vehicles[i].second;
        int min_year;
        std::cin >> min_year;
        for (const auto& v : vehicles) if (v.second > min_year) std::cout << v.first << "\n";
    }
    return 0;
}