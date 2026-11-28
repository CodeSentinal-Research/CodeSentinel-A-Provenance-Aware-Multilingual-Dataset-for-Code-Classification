#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    if(n == 1) { printf("%d\n", a[0]); return 0; }
    long long incl = a[0], excl = 0;
    for(int i=1; i<n-1; i++) { long long new_excl = incl > excl ? incl : excl; incl = excl + a[i]; excl = new_excl; }
    long long res1 = incl > excl ? incl : excl;
    incl = a[1]; excl = 0;
    for(int i=2; i<n; i++) { long long new_excl = incl > excl ? incl : excl; incl = excl + a[i]; excl = new_excl; }
    long long res2 = incl > excl ? incl : excl;
    printf("%lld\n", res1 > res2 ? res1 : res2);
    return 0;
}
