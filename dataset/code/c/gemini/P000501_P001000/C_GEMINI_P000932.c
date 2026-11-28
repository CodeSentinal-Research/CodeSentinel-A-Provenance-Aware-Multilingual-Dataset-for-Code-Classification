#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        long long trace = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val;
                scanf("%d", &val);
                if (i == j) trace += val;
            }
        }
        printf("%lld\n", trace);
    }
    return 0;
}