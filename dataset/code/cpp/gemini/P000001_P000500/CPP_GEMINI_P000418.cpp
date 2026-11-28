#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> emps(n);
        for (int i = 0; i < n; i++) std::cin >> emps[i].first >> emps[i].second;
        std::string date_thresh;
        std::cin >> date_thresh;
        for (const auto& e : emps) if (e.second < date_thresh) std::cout << e.first << "\n";
    }
    return 0;
}