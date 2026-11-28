#include <stdio.h>
void gen(int *a, int n, int i, int *curr, int ci) { if(i==n) { for(int j=0;j<ci;j++) printf("%d ",curr[j]); printf("\n"); return; } gen(a,n,i+1,curr,ci); curr[ci]=a[i]; gen(a,n,i+1,curr,ci+1); }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); int curr[n]; gen(a,n,0,curr,0); return 0; }
