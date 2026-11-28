#include <stdio.h>

int lastInternalNode(int n) {
    if (n <= 1) return -1;
    return n / 2 - 1;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", lastInternalNode(n));
    }
    return 0;
}