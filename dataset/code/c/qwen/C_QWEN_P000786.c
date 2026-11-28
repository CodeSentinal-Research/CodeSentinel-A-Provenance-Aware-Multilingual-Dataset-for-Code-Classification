#include <stdio.h>
#include <stdlib.h>
int main() { int n; scanf("%d",&n); long long a[n]; long long total=0; for(int i=0;i<n;i++) { scanf("%lld",&a[i]); total+=a[i]; } long long left=0; for(int i=0;i<n;i++) { long long right=total-left-a[i]; printf("%lld ",abs(left-right)); left+=a[i]; } printf("\n"); return 0; }
