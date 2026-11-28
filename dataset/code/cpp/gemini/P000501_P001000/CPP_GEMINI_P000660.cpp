#include <iostream>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        if (n == 0) { std::cout << -1 << std::endl; return 0; }
        int max_v; std::cin >> max_v;
        for (int i = 1; i < n; i++) {
            int x; std::cin >> x;
            if (x > max_v) max_v = x;
        }
        std::cout << max_v << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}