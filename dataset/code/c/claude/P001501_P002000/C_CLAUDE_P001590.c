#include <stdio.h>
int main(){int n,k;scanf("%d %d",&n,&k);long long a[n];for(int i=0;i<n;i++)scanf("%lld",&a[i]);long long s=0,mx;for(int i=0;i<k;i++)s+=a[i];mx=s;for(int i=k;i<n;i++){s+=a[i]-a[i-k];if(s>mx)mx=s;}printf("%lld\n",mx);return 0;}
