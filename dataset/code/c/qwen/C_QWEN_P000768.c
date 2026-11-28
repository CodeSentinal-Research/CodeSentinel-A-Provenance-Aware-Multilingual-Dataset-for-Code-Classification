#include <stdio.h>
int count(int n) { if(n<=1) return 1; int total=0; for(int i=1;i<=n;i++) total+=count(i-1)*count(n-i); return total; }
int main() { int n; scanf("%d",&n); printf("%d\n",count(n)); return 0; }
