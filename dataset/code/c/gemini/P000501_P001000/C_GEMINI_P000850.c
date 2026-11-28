#include <stdio.h>
#include <stdbool.h>

bool isKthBitSet(int n, int k) {
    return (n & (1 << k)) != 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        printf("%s\n", isKthBitSet(n, k) ? "YES" : "NO");
    }
    return 0;
}