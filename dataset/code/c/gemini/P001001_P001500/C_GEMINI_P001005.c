#include <stdio.h>

int countLeafNodes(int n) {
    return (n + 1) / 2;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", countLeafNodes(n));
    }
    return 0;
}