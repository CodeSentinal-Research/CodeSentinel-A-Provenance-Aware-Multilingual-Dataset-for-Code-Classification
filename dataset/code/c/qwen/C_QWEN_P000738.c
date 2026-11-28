#include <stdio.h>
int n, count=0, used[16];
void solve(int i) { if(i>n) { count++; return; } for(int j=1;j<=n;j++) { if(!used[j] && (j%i==0 || i%j==0)) { used[j]=1; solve(i+1); used[j]=0; } } }
int main() { scanf("%d",&n); solve(1); printf("%d\n",count); return 0; }
