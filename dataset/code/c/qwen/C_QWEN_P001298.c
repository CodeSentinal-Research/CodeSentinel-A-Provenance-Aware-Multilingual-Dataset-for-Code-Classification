#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long sum = 0, max_val = 0;
    for(int i=0; i<n; i++) { sum += a[i]; if(a[i] > max_val) max_val = a[i]; }
    if(max_val > sum - max_val + 1) printf("%lld\n", 2*(sum - max_val) + 1);
    else printf("%lld\n", sum);
    return 0;
}
