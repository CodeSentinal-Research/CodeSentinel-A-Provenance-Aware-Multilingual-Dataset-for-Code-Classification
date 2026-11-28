#include <stdio.h>
int main() { int n,k; scanf("%d%d",&n,&k); int a[n], prefix[n+1]; prefix[0]=0; for(int i=0;i<n;i++) { scanf("%d",&a[i]); prefix[i+1]=prefix[i]+(a[i]%2!=0?1:0); } int count=0; for(int i=0;i<=n;i++) for(int j=i+1;j<=n;j++) if(prefix[j]-prefix[i]==k) count++; printf("%d\n",count); return 0; }
