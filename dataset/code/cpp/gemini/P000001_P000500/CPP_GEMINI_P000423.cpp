#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, int>> orders(n);
        for (int i = 0; i < n; i++) std::cin >> orders[i].first >> orders[i].second;
        int days;
        std::cin >> days;
        for (const auto& o : orders) if (o.second > days) std::cout << o.first << "\n";
    }
    return 0;
}