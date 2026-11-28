#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long incl = a[0], excl = 0;
    for(int i=1; i<n; i++) {
        long long new_excl = incl > excl ? incl : excl;
        incl = excl + a[i];
        excl = new_excl;
    }
    printf("%lld\n", incl > excl ? incl : excl);
    return 0;
}
