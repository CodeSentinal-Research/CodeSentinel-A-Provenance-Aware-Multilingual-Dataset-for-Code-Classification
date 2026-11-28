#include <iostream>
#include <vector>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<int> inDegree(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            inDegree[v]++;
        }
        int count = 0;
        for (int d : inDegree) {
            if (d == 0) count++;
        }
        std::cout << count << "\n";
    }
    return 0;
}