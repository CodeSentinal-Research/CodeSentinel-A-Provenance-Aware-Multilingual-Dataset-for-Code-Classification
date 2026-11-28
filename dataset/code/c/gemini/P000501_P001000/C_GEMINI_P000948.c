#include <stdio.h>

// Solves 'Chessboard Game' by applying optimal Mathematics - Game Theory logic.
void solve() {
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) return;
    x = (x - 1) % 4;
    y = (y - 1) % 4;
    if ((x == 0 || x == 1) && (y == 0 || y == 1)) {
        printf("Second\n");
    } else {
        printf("First\n");
    }
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) solve();
    }
    return 0;
}