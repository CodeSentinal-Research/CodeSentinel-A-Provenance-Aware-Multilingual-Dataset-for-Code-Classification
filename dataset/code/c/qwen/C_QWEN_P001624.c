#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    long long diff[n], res[n];
    for(int i=0; i<n; i++) scanf("%lld", &diff[i]);
    res[0] = diff[0];
    for(int i=1; i<n; i++) res[i] = res[i-1] + diff[i];
    for(int i=0; i<n; i++) printf("%lld%c", res[i], i==n-1?'\n':' ');
    return 0;
}
