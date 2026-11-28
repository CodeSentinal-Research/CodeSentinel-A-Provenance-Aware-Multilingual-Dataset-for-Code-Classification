#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> events(n);
        for (int i = 0; i < n; i++) std::cin >> events[i].first >> events[i].second;
        std::string date;
        std::cin >> date;
        for (const auto& e : events) if (e.second == date) std::cout << e.first << "\n";
    }
    return 0;
}