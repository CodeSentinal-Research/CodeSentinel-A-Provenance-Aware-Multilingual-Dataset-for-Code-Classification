#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long hold = -a[0], sold = 0, rest = 0;
    for(int i=1; i<n; i++) {
        long long new_hold = hold > rest - a[i] ? hold : rest - a[i];
        long long new_sold = hold + a[i];
        long long new_rest = sold > rest ? sold : rest;
        hold = new_hold; sold = new_sold; rest = new_rest;
    }
    printf("%lld\n", sold > rest ? sold : rest);
    return 0;
}
