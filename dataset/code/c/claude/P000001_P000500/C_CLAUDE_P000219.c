#include <stdio.h>
int main(){int n,k;scanf("%d %d",&n,&k);long long a[n];for(int i=0;i<n;i++)scanf("%lld",&a[i]);long long p=1;for(int i=n-k;i<n;i++)p*=a[i];printf("%lld\n",p);}
