#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            if (v == i && ans == -1) ans = i;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}