#include <iostream>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
        }
        std::cout << m << "\n";
    }
    return 0;
}