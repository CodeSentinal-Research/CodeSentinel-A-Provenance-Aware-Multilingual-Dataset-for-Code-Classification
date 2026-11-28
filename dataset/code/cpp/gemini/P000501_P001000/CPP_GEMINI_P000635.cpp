#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int g; std::cin >> g;
        std::vector<int> groups(g);
        for (int i = 0; i < g; i++) std::cin >> groups[i];
        int cur = 0;
        for (int sz : groups) {
            if (cur + sz <= n) {
                std::reverse(vals.begin() + cur, vals.begin() + cur + sz);
                cur += sz;
            } else {
                break;
            }
        }
        for (int i = 0; i < n; i++) std::cout << vals[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}