#include <stdio.h>
#include <stdlib.h>
int n, minDiff=2147483647;
void solve(int *a, int i, int sum1, int sum2, int c1, int c2) { if(i==n) { int diff=abs(sum1-sum2); if(diff<minDiff) minDiff=diff; return; } if(c1<(n+1)/2) solve(a,i+1,sum1+a[i],sum2,c1+1,c2); if(c2<(n+1)/2) solve(a,i+1,sum1,sum2+a[i],c1,c2+1); }
int main() { scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); solve(a,0,0,0,0,0); printf("%d\n",minDiff); return 0; }
