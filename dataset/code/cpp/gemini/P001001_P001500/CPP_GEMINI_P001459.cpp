#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            set.insert(x);
        }
        int i = 1;
        // Shrink window from the left while duplicate element exists
        while (set.count(i)) i++;
        std::cout << i << "\n";
    }
    return 0;
}