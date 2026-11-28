#include <stdio.h>
int main() { int n,k; scanf("%d%d",&n,&k); long long a[n], prefix[n+1]; prefix[0]=0; for(int i=0;i<n;i++) { scanf("%lld",&a[i]); prefix[i+1]=prefix[i]+a[i]; } int found=0; for(int i=0;i<=n && !found;i++) for(int j=i+2;j<=n && !found;j++) if((prefix[j]-prefix[i])%k==0) found=1; printf("%s\n",found?"true":"false"); return 0; }
