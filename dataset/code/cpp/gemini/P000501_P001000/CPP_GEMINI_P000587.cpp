#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int k;
    if (std::cin >> k) {
        std::vector<int> all_vals;
        for (int i = 0; i < k; i++) {
            int size; std::cin >> size;
            for (int j = 0; j < size; j++) {
                int v; std::cin >> v;
                all_vals.push_back(v);
            }
        }
        std::sort(all_vals.begin(), all_vals.end());
        for (size_t i = 0; i < all_vals.size(); i++) {
            std::cout << all_vals[i] << (i + 1 == all_vals.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}