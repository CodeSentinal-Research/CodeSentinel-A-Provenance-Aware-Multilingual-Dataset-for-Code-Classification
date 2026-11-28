#include <iostream>
#include <vector>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            if (v == target && idx == -1) idx = i;
        }
        std::cout << idx << std::endl;
    }
    return 0;
}