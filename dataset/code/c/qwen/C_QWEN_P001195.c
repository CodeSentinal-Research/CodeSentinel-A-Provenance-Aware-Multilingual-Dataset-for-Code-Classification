#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a[n]; for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    long long even = 0, odd = 0;
    for(int i=0; i<n; i++) {
        long long new_even = even > odd - a[i] ? even : odd - a[i];
        long long new_odd = odd > even + a[i] ? odd : even + a[i];
        even = new_even; odd = new_odd;
    }
    printf("%lld\n", even > odd ? even : odd);
    return 0;
}
