#include <iostream>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        int a, b, c;
        std::cin >> a >> b >> c;
        for (int i = 1; i < n; i++) {
            int x, y, z;
            std::cin >> x >> y >> z;
            int na = x + std::max(b, c);
            int nb = y + std::max(a, c);
            int nc = z + std::max(a, b);
            a = na; b = nb; c = nc;
        }
        std::cout << std::max({a, b, c}) << "\n";
    }
    return 0;
}