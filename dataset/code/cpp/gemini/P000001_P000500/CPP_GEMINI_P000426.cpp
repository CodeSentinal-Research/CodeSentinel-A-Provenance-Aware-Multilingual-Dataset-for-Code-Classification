#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, double>> rests(n);
        for (int i = 0; i < n; i++) std::cin >> rests[i].first >> rests[i].second;
        double threshold;
        std::cin >> threshold;
        for (const auto& r : rests) if (r.second >= threshold) std::cout << r.first << "\n";
    }
    return 0;
}