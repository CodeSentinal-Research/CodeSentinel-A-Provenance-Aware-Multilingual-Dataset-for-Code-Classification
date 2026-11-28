#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            ans ^= v;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}