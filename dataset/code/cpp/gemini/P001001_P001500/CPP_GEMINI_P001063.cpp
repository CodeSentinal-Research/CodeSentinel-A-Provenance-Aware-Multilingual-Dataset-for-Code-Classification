#include <iostream>
#include <vector>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<int> outDegree(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            outDegree[u]++;
        }
        int count = 0;
        for (int d : outDegree) {
            if (d == 0) count++;
        }
        std::cout << count << "\n";
    }
    return 0;
}