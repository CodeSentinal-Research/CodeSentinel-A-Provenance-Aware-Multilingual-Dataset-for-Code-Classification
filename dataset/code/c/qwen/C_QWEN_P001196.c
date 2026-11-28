#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long count = 0, len = 0;
    for(int i=2; i<n; i++) {
        if(a[i] - a[i-1] == a[i-1] - a[i-2]) { len++; count += len; }
        else len = 0;
    }
    printf("%lld\n", count);
    return 0;
}
