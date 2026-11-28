#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            set.insert(std::abs(x));
        }
        std::cout << set.size() << "\n";
    }
    return 0;
}