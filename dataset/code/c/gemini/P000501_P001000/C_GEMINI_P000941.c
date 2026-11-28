#include <stdio.h>

// Solves 'Standard Nim Game' by applying optimal Mathematics - Game Theory logic.
void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        xorSum ^= x;
    }
    printf("%s\n", (xorSum != 0) ? "First" : "Second");
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) solve();
    }
    return 0;
}