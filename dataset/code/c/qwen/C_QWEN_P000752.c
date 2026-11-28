#include <stdio.h>
int found=0;
void gen(int *a, int n, int i, int t, int *curr, int ci) { if(found) return; if(t==0) { for(int j=0;j<ci;j++) printf("%d ",curr[j]); printf("\n"); found=1; return; } if(i==n) return; curr[ci]=a[i]; gen(a,n,i+1,t-a[i],curr,ci+1); gen(a,n,i+1,t,curr,ci); }
int main() { int n,t; scanf("%d%d",&n,&t); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); int curr[n]; gen(a,n,0,t,curr,0); if(!found) printf("-1\n"); return 0; }
