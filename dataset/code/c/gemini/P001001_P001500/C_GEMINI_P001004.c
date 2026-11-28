#include <stdio.h>
#include <math.h>

int heapHeight(int n) {
    if (n <= 0) return 0;
    return (int)log2(n);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", heapHeight(n));
    }
    return 0;
}