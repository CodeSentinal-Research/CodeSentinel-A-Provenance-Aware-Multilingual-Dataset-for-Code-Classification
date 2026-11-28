#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int inc[n], dec[n];
    for(int i=0; i<n; i++) { inc[i] = 1; for(int j=0; j<i; j++) if(a[j] < a[i] && inc[j]+1 > inc[i]) inc[i] = inc[j]+1; }
    for(int i=n-1; i>=0; i--) { dec[i] = 1; for(int j=n-1; j>i; j--) if(a[j] < a[i] && dec[j]+1 > dec[i]) dec[i] = dec[j]+1; }
    int max_l = 0;
    for(int i=0; i<n; i++) if(inc[i]+dec[i]-1 > max_l) max_l = inc[i]+dec[i]-1;
    printf("%d\n", max_l);
    return 0;
}
