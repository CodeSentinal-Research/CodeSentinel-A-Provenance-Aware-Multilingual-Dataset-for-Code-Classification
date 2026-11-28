#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, double>> employees(n);
        for (int i = 0; i < n; i++) {
            std::cin >> employees[i].first >> employees[i].second;
        }
        double min_sal, max_sal;
        std::cin >> min_sal >> max_sal;
        for (const auto& e : employees) {
            if (e.second >= min_sal && e.second <= max_sal) {
                std::cout << e.first << "\n";
            }
        }
    }
    return 0;
}