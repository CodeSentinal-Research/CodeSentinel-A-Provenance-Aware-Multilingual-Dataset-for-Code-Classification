#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n], b[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    long long sum_a = 0;
    for(int i=0; i<n; i++) sum_a += a[i];
    int max_diff = 0;
    for(int i=0; i<n; i++) {
        int diff = b[i] - a[i];
        if(diff > max_diff) max_diff = diff;
    }
    printf("%lld\n", sum_a + max_diff);
    return 0;
}
