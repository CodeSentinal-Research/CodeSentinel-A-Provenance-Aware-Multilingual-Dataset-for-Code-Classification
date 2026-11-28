#include <stdio.h>
void gen(int t, int *curr, int ci) { if(t==0) { for(int i=0;i<ci;i++) printf("%d ",curr[i]); printf("\n"); return; } for(int i=1;i<=6 && i<=t;i++) { curr[ci]=i; gen(t-i,curr,ci+1); } }
int main() { int t; scanf("%d",&t); int curr[t]; gen(t,curr,0); return 0; }
