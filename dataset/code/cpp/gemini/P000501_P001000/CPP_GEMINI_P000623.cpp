#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int k; std::cin >> k;
        bool rev = true;
        for (int i = 0; i < n; i += k) {
            int len = std::min(k, n - i);
            if (rev) std::reverse(vals.begin() + i, vals.begin() + i + len);
            rev = !rev;
        }
        for (int i = 0; i < n; i++) std::cout << vals[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}