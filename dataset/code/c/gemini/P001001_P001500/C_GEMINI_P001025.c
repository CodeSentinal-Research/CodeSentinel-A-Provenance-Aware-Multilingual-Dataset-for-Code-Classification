#include <stdio.h>

int countInternalNodes(int n) {
    return n / 2;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", countInternalNodes(n));
    }
    return 0;
}