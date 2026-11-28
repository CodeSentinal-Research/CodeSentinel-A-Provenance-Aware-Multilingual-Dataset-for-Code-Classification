#include <stdio.h>
#include <stdbool.h>

// Solves 'Misère Nim' by applying optimal Mathematics - Game Theory logic.
void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    bool allOnes = true;
    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x > 1) allOnes = false;
        xorSum ^= x;
    }
    if (allOnes) {
        printf("%s\n", (n % 2 == 0) ? "First" : "Second");
    } else {
        printf("%s\n", (xorSum != 0) ? "First" : "Second");
    }
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) solve();
    }
    return 0;
}