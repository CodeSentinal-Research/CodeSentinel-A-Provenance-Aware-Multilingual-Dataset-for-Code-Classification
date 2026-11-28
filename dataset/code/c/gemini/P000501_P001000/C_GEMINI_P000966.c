#include <stdio.h>
#include <stdbool.h>

int main() {
    long long x;
    int k;
    if (scanf("%lld %d", &x, &k) == 2 && k > 0) {
        long long num[k], rem[k];
        for (int i = 0; i < k; i++) scanf("%lld", &num[i]);
        for (int i = 0; i < k; i++) scanf("%lld", &rem[i]);
        bool ok = true;
        for (int i = 0; i < k; i++) {
            if (x % num[i] != rem[i]) {
                ok = false;
                break;
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}