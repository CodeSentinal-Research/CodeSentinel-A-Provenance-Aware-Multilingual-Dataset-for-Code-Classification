#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        int closest = 0, min_diff = INT_MAX;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            int diff = std::abs(v - target);
            if (diff < min_diff) {
                min_diff = diff;
                closest = v;
            }
        }
        std::cout << closest << std::endl;
    }
    return 0;
}