#include <stdio.h>
int main() { int n; scanf("%d",&n); int a[n], prefix[n+1]; prefix[0]=0; for(int i=0;i<n;i++) { scanf("%d",&a[i]); prefix[i+1]=prefix[i]+(a[i]==0?-1:1); } int count[2*n+1]={0}; count[n]=1; int total=0; for(int i=1;i<=n;i++) { total+=count[prefix[i]+n]; count[prefix[i]+n]++; } printf("%d\n",total); return 0; }
