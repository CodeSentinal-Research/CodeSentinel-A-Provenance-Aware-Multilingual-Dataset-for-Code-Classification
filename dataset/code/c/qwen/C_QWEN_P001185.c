#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int max_val = 0;
    for(int i=0; i<n; i++) if(a[i] > max_val) max_val = a[i];
    long long count[max_val+1]; for(int i=0; i<=max_val; i++) count[i] = 0;
    for(int i=0; i<n; i++) count[a[i]] += a[i];
    long long incl = count[0], excl = 0;
    for(int i=1; i<=max_val; i++) {
        long long new_excl = incl > excl ? incl : excl;
        incl = excl + count[i];
        excl = new_excl;
    }
    printf("%lld\n", incl > excl ? incl : excl);
    return 0;
}
