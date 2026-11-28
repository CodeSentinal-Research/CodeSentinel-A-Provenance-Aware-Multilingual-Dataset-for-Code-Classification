#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int k; std::cin >> k;
        if (k == 1) return 0;
        bool first = true;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % k != 0) {
                if (!first) std::cout << " ";
                std::cout << vals[i];
                first = false;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}