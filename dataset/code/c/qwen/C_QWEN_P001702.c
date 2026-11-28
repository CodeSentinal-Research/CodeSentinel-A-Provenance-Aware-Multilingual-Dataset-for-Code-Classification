#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long val[n];
    for(int i=0; i<n; i++) scanf("%lld", &val[i]);
    printf("%d\n", n);
    return 0;
}
