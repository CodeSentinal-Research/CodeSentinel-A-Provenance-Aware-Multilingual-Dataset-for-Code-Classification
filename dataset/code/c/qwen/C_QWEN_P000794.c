#include <stdio.h>
int main() { int n,k; scanf("%d%d",&n,&k); long long a[n], prefix[n+1]; prefix[0]=0; for(int i=0;i<n;i++) { scanf("%lld",&a[i]); prefix[i+1]=prefix[i]+a[i]; } int maxLen=0; for(int i=0;i<=n;i++) for(int j=n;j>i;j--) if(prefix[j]-prefix[i]==k) { if(j-i>maxLen) maxLen=j-i; break; } printf("%d\n",maxLen); return 0; }
