#include <iostream>
#include <vector>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::pair<int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            std::cin >> edges[i].first >> edges[i].second;
        }
        std::vector<int> colors(n);
        for (int i = 0; i < n; i++) std::cin >> colors[i];

        bool valid = true;
        for (const auto& e : edges) {
            if (colors[e.first] == colors[e.second]) {
                valid = false;
                break;
            }
        }
        std::cout << (valid ? "VALID" : "INVALID") << "\n";
    }
    return 0;
}