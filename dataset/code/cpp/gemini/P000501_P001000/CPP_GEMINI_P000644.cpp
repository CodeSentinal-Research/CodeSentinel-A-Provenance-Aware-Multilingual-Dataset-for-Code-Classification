#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int x, y; std::cin >> x >> y;
        auto it1 = std::find(vals.begin(), vals.end(), x);
        auto it2 = std::find(vals.begin(), vals.end(), y);
        if (it1 != vals.end() && it2 != vals.end()) {
            std::iter_swap(it1, it2);
        }
        for (size_t i = 0; i < vals.size(); i++) {
            std::cout << vals[i] << (i + 1 == vals.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}