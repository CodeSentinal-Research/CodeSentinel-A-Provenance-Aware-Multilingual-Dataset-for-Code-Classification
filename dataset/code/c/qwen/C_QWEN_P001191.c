#include <stdio.h>
int main() {
    int n, fee; scanf("%d%d", &n, &fee);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long hold = -a[0], sold = 0;
    for(int i=1; i<n; i++) {
        long long new_hold = hold > sold - a[i] ? hold : sold - a[i];
        long long new_sold = hold + a[i] - fee > sold ? hold + a[i] - fee : sold;
        hold = new_hold; sold = new_sold;
    }
    printf("%lld\n", sold);
    return 0;
}
