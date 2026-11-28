#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> patients(n);
        for (int i = 0; i < n; i++) std::cin >> patients[i].first >> patients[i].second;
        std::string blood;
        std::cin >> blood;
        for (const auto& p : patients) if (p.second == blood) std::cout << p.first << "\n";
    }
    return 0;
}