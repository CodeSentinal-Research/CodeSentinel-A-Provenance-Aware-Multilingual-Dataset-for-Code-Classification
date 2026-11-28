#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> q(n);
        for (int i = 0; i < n; i++) std::cin >> q[i];
        int k; std::cin >> k;
        k %= n;
        for (int i = 0; i < n; i++) {
            std::cout << q[(i + k) % n] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}