#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, double>> prods(n);
        for (int i = 0; i < n; i++) std::cin >> prods[i].first >> prods[i].second;
        double min_p;
        std::cin >> min_p;
        for (const auto& p : prods) if (p.second >= min_p) std::cout << p.first << "\n";
    }
    return 0;
}