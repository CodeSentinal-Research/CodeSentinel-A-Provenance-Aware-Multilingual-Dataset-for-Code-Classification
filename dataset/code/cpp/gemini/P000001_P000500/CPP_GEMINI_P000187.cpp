#include <iostream>
#include <vector>
#include <unordered_set>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::unordered_set<long long> set;
        for (int i = 0; i < n; i++) {
            long long x;
            std::cin >> x;
            set.insert(x);
        }
        long long val = 1;
        // Shrink window from the left while duplicate element exists
        while (set.count(val)) val++;
        std::cout << val << std::endl;
    }
    return 0;
}