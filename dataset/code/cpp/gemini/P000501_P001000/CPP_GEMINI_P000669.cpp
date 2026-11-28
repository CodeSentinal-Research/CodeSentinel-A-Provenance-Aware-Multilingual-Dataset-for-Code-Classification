#include <iostream>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        if (n == 0) { std::cout << -1 << std::endl; return 0; }
        int min_v; std::cin >> min_v;
        for (int i = 1; i < n; i++) {
            int x; std::cin >> x;
            if (x < min_v) min_v = x;
        }
        std::cout << min_v << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}