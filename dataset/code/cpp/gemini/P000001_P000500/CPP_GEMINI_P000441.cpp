#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        int max_val = -2e9;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            if (v > max_val) max_val = v;
        }
        std::cout << max_val << std::endl;
    }
    return 0;
}