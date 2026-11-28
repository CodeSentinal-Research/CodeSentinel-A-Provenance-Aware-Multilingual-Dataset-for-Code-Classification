#include <iostream>
int main() {
    int target;
    if (std::cin >> target) {
        int v, idx = 0, ans = -1;
        while (std::cin >> v) {
            if (v == target && ans == -1) ans = idx;
            idx++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}