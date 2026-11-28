#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        bool less = true;
        for (int i = 0; i < n - 1; i++) {
            if (less) {
                if (vals[i] > vals[i + 1]) std::swap(vals[i], vals[i + 1]);
            } else {
                if (vals[i] < vals[i + 1]) std::swap(vals[i], vals[i + 1]);
            }
            less = !less;
        }
        for (size_t i = 0; i < vals.size(); i++) {
            std::cout << vals[i] << (i + 1 == vals.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}