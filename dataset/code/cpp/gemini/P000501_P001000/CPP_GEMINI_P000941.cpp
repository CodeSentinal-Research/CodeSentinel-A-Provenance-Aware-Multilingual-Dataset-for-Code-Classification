#include <iostream>
#include <vector>

// Solves 'Standard Nim Game' by applying optimal Mathematics - Game Theory logic.
void solve() {
    int n;
    if (!(std::cin >> n)) return;
    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        xorSum ^= x;
    }
    std::cout << ((xorSum != 0) ? "First" : "Second") << "\n";
}

int main() {
    int t;
    if (std::cin >> t) {
        while (t--) solve();
    }
    return 0;
}