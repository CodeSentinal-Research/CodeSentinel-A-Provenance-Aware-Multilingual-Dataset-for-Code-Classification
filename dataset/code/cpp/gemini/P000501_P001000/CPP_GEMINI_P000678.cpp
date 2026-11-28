#include <iostream>
int main() {
    int n, k;
    if (std::cin >> n >> k) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }
        std::cout << ans + 1 << std::endl;
    }
    return 0;
}