#include <stdio.h>

int setKthBit(int n, int k) {
    return n | (1 << k);
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        printf("%d\n", setKthBit(n, k));
    }
    return 0;
}