#include <stdio.h>
#include <stdbool.h>

bool isNeonNumber(int n) {
    if (n < 0) return false;
    long long sq = (long long) n * n;
    long long sum = 0;
    while (sq > 0) {
        sum += sq % 10;
        sq /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%s\n", isNeonNumber(n) ? "YES" : "NO");
    }
    return 0;
}