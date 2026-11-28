#include <stdio.h>
int main() {
    int m; long long n; scanf("%d%lld", &m, &n);
    long long a[m]; for(int i=0; i<m; i++) scanf("%lld", &a[i]);
    int patches = 0;
    long long reach = 1;
    int i = 0;
    while(reach <= n) {
        if(i < m && a[i] <= reach) { reach += a[i]; i++; }
        else { reach += reach; patches++; }
    }
    printf("%d\n", patches);
    return 0;
}
