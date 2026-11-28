#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        int m;
        if (std::cin >> m) {
            std::vector<int> b(m);
            for (int i = 0; i < m; i++) std::cin >> b[i];
            std::cout << ((a == b) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}