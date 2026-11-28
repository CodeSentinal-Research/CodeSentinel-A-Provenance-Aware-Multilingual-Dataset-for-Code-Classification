#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        int max_v = -2e9;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            if (v > max_v) max_v = v;
        }
        std::cout << max_v << std::endl;
    }
    return 0;
}