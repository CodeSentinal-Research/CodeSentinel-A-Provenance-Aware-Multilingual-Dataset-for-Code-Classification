#include <stdio.h>
void gen(int n, int *curr, int ci, int prev) { if(ci==n) { for(int i=0;i<n;i++) printf("%d",curr[i]); printf("\n"); return; } for(int i=0;i<2;i++) { if(ci>0 && prev==1 && i==1) continue; curr[ci]=i; gen(n,curr,ci+1,i); } }
int main() { int n; scanf("%d",&n); int curr[n]; gen(n,curr,0,0); return 0; }
