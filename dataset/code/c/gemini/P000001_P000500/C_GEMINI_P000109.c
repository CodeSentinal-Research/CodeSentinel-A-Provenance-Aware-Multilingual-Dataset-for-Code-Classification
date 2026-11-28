#include <stdio.h>
int main() {
    int n;
    long long target;
    if (scanf("%d %lld", &n, &target) == 2) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            long long val;
            scanf("%lld", &val);
            if (val == target && idx == -1) idx = i;
        }
        printf("%d\n", idx);
    }
    return 0;
}