#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, int>> accs(n);
        for (int i = 0; i < n; i++) std::cin >> accs[i].first >> accs[i].second;
        int m;
        std::cin >> m;
        for (const auto& a : accs) if (a.second >= m) std::cout << a.first << "\n";
    }
    return 0;
}