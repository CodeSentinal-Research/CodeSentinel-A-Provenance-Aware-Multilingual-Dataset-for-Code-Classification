#include <iostream>

// Solves 'Chessboard Game' by applying optimal Mathematics - Game Theory logic.
void solve() {
    int x, y;
    if (!(std::cin >> x >> y)) return;
    x = (x - 1) % 4;
    y = (y - 1) % 4;
    if ((x == 0 || x == 1) && (y == 0 || y == 1)) {
        std::cout << "Second\n";
    } else {
        std::cout << "First\n";
    }
}

int main() {
    int t;
    if (std::cin >> t) {
        while (t--) solve();
    }
    return 0;
}