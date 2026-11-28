#include <stdio.h>
void gen(int *a, int n, int t, int i, int *curr, int ci, int sum) { if(sum==t) { for(int j=0;j<ci;j++) printf("%d ",curr[j]); printf("\n"); return; } if(sum>t || i==n) return; curr[ci]=a[i]; gen(a,n,t,i,curr,ci+1,sum+a[i]); gen(a,n,t,i+1,curr,ci,sum); }
int main() { int n,t; scanf("%d%d",&n,&t); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); int curr[n]; gen(a,n,t,0,curr,0,0); return 0; }
