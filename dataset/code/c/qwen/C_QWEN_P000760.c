#include <stdio.h>
void gen(int n, int d, int curr) { if(d==n) { printf("%d\n",curr); return; } int start=d==0?1:0; for(int i=start;i<=9;i++) if(i>curr%10 || d==0) gen(n,d+1,curr*10+i); }
int main() { int n; scanf("%d",&n); gen(n,0,0); return 0; }
