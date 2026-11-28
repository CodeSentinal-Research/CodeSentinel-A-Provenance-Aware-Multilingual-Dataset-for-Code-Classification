#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            if (v == 1 && idx == -1) idx = i;
        }
        std::cout << idx << std::endl;
    }
    return 0;
}