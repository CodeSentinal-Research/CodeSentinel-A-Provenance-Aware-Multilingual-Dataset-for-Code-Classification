#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        for (int i = 0; i + 1 < n; i += 2) {
            std::swap(vals[i], vals[i + 1]);
        }
        for (size_t i = 0; i < vals.size(); i++) {
            std::cout << vals[i] << (i + 1 == vals.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}