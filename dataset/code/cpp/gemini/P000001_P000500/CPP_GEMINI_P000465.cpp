#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
int main() {
    int n, diff;
    if (std::cin >> n >> diff) {
        diff = std::abs(diff);
        std::unordered_set<int> seen;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            if (seen.count(v - diff) || seen.count(v + diff)) found = true;
            seen.insert(v);
        }
        std::cout << (found ? "Yes" : "No") << std::endl;
    }
    return 0;
}