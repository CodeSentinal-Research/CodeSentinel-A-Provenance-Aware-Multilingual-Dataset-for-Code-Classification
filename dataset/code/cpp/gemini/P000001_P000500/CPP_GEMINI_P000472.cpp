#include <iostream>
#include <algorithm>
int main() {
    int r, c;
    if (std::cin >> r >> c) {
        int max_v = -2e9;
        for (int i = 0; i < r * c; i++) {
            int v;
            std::cin >> v;
            if (v > max_v) max_v = v;
        }
        std::cout << max_v << std::endl;
    }
    return 0;
}