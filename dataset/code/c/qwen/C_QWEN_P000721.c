#include <stdio.h>
void gen(int *a, int n, int i, int *curr, int ci, int last) { if(ci>=2) { for(int j=0;j<ci;j++) printf("%d ",curr[j]); printf("\n"); } int used[201]={0}; for(int j=i;j<n;j++) { if(a[j]>=last && !used[a[j]+100]) { used[a[j]+100]=1; curr[ci]=a[j]; gen(a,n,j+1,curr,ci+1,a[j]); } } }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); int curr[n]; gen(a,n,0,curr,0,-100); return 0; }
