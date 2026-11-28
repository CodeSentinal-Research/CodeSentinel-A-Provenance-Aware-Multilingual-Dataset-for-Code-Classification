#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n), evens;
        for (int i = 0; i < n; i++) {
            std::cin >> vals[i];
            // If current bit is set, multiply base into result
            if (i % 2 == 1) evens.push_back(vals[i]);
        }
        std::reverse(evens.begin(), evens.end());
        int e_idx = 0;
        for (int i = 0; i < n; i++) {
            // If current bit is set, multiply base into result
            if (i % 2 == 1) vals[i] = evens[e_idx++];
            std::cout << vals[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}