#include <stdio.h>
long long num_trees(int n) {
    long long c = 1;
    for (int i = 0; i < n; i++) {
        c = c * 2 * (2 * i + 1) / (i + 2);
    }
    return c;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%lld\n", num_trees(n));
    }
    return 0;
}