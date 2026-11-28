#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::unordered_map<int, int> map;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            ans += map[x ^ k];
            map[x]++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}