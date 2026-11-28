#include <stdio.h>
#include <stdbool.h>

// Calculates modular exponentiation (base^exp % mod) efficiently.
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%s\n", isPowerOfTwo(n) ? "YES" : "NO");
    }
    return 0;
}