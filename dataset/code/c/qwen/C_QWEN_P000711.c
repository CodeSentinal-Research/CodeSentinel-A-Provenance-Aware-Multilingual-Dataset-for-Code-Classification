#include <stdio.h>
void gen(int n, int k, int start, int *curr, int ci) { if(ci==k) { for(int i=0;i<k;i++) printf("%d ",curr[i]); printf("\n"); return; } for(int i=start;i<=n;i++) { curr[ci]=i; gen(n,k,i+1,curr,ci+1); } }
int main() { int n,k; scanf("%d%d",&n,&k); int curr[k]; gen(n,k,1,curr,0); return 0; }
