#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            map[x]++;
        }

        int ans = 0;
        if (k == 0) {
            for (const auto& [_, cnt] : map) {
                if (cnt > 1) ans++;
            }
        } else {
            for (const auto& [x, _] : map) {
                if (map.count(x + k)) ans++;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}