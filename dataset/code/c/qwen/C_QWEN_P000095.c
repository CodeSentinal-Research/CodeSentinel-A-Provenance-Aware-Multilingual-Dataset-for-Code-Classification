#include <stdio.h>

int main() {
    int n, s = 0;
    scanf("%d", &n);
    int sq = n * n;
    while (sq > 0) { s += sq % 10; sq /= 10; }
    printf("%s\n", s == n ? "Neon" : "Not Neon");
    return 0;
}
