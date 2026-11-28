#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int b; std::cin >> b;
            ans = (ans << 1) | b;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}