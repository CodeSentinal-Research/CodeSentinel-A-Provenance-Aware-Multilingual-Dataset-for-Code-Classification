#include <stdio.h>

int main(void) {
    int num;
    if (scanf("%d", &num) != 1) return 1;
    int original = num, sq = num * num, sum = 0; while (sq > 0) { sum += sq % 10; sq /= 10; } printf("%s\n", sum == original ? "Neon" : "Not Neon");
    return 0;
}
