#include <stdio.h>
void gen(int *a, int n, int i, int t, int *curr, int ci) { if(t==0) { for(int j=0;j<ci;j++) printf("%d ",curr[j]); printf("\n"); return; } if(i==n) return; curr[ci]=a[i]; gen(a,n,i+1,t-a[i],curr,ci+1); gen(a,n,i+1,t,curr,ci); }
int main() { int n,t; scanf("%d%d",&n,&t); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); int curr[n]; gen(a,n,0,t,curr,0); return 0; }
