#include <stdio.h>
int main() { int n,k; scanf("%d%d",&n,&k); int a[n], prefix[n+1]; prefix[0]=0; for(int i=0;i<n;i++) { scanf("%d",&a[i]); prefix[i+1]=((prefix[i]+a[i])%k+k)%k; } int count[10001]={0}; count[0]=1; int total=0; for(int i=1;i<=n;i++) { total+=count[prefix[i]]; count[prefix[i]]++; } printf("%d\n",total); return 0; }
