#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long s = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x); s += x;
        }
        printf("%lld\n", s);
    }
    return 0;
}