#include <iostream>
#include <vector>

// Solves 'Misère Nim' by applying optimal Mathematics - Game Theory logic.
void solve() {
    int n;
    if (!(std::cin >> n)) return;
    bool allOnes = true;
    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x > 1) allOnes = false;
        xorSum ^= x;
    }
    if (allOnes) {
        std::cout << ((n % 2 == 0) ? "First" : "Second") << "\n";
    } else {
        std::cout << ((xorSum != 0) ? "First" : "Second") << "\n";
    }
}

int main() {
    int t;
    if (std::cin >> t) {
        while (t--) solve();
    }
    return 0;
}