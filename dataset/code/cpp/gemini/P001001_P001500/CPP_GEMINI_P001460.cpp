#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_map<int, int> map;
        map[0] = 1;
        int prefix = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            prefix ^= x;
            ans += map[prefix];
            map[prefix]++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}