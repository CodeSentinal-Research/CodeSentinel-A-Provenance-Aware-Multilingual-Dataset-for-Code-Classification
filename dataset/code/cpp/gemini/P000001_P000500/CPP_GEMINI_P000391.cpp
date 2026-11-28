#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, double>> students(n);
        for (int i = 0; i < n; i++) {
            std::cin >> students[i].first >> students[i].second;
        }
        double threshold;
        std::cin >> threshold;
        for (const auto& s : students) {
            if (s.second >= threshold) {
                std::cout << s.first << "\n";
            }
        }
    }
    return 0;
}