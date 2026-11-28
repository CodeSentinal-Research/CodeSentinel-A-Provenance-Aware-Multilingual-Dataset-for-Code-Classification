#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int cur = 0, group_len = 1;
        while (cur < n) {
            int actual_len = std::min(group_len, n - cur);
            if (actual_len % 2 == 0) {
                std::reverse(vals.begin() + cur, vals.begin() + cur + actual_len);
            }
            cur += actual_len;
            group_len++;
        }
        for (int i = 0; i < n; i++) {
            std::cout << vals[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}