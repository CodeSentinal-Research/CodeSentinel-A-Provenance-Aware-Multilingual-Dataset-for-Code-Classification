#include <stdio.h>
int solve(int n, int k) { if(n==1) return 0; int len=1<<(n-1); if(k>len/2) return 1-solve(n-1,k-len/2); return solve(n-1,k); }
int main() { int n,k; scanf("%d%d",&n,&k); printf("%d\n",solve(n,k)); return 0; }
