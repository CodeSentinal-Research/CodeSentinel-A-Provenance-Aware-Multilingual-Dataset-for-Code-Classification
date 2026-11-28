#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a[n]; for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    long long max_p = a[0], min_p = a[0], res = a[0];
    for(int i=1; i<n; i++) {
        long long t1 = max_p * a[i], t2 = min_p * a[i];
        max_p = t1 > t2 ? t1 : t2; min_p = t1 < t2 ? t1 : t2;
        if(a[i] > max_p) max_p = a[i]; if(a[i] < min_p) min_p = a[i];
        if(max_p > res) res = max_p;
    }
    printf("%lld\n", res);
    return 0;
}
