#include <stdio.h>
int main() { int n; scanf("%d",&n); long long a[n]; for(int i=0;i<n;i++) scanf("%lld",&a[i]); for(int i=1;i<n;i++) a[i]+=a[i-1]; for(int i=0;i<n;i++) printf("%lld ",a[i]); printf("\n"); return 0; }
