#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    long long a[n], b[n];
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    for(int i=0; i<n; i++) scanf("%lld", &b[i]);
    long long ops = 0, diff = 0;
    for(int i=0; i<n; i++) {
        diff += b[i] - a[i];
        if(diff > 0) ops += diff;
    }
    printf("%lld\n", ops);
    return 0;
}
