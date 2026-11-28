#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, int>> books(n);
        for (int i = 0; i < n; i++) {
            std::cin >> books[i].first >> books[i].second;
        }
        int min_year;
        std::cin >> min_year;
        for (const auto& b : books) {
            if (b.second > min_year) {
                std::cout << b.first << "\n";
            }
        }
    }
    return 0;
}