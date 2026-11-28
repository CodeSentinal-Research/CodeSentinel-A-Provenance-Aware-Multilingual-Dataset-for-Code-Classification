#include <stdio.h>
int main(){int n,k;scanf("%d %d",&n,&k);long long a[n];for(int i=0;i<n;i++)scanf("%lld",&a[i]);long long s=0;for(int i=0;i<k;i++)s+=a[i];printf("%lld\n",s);for(int i=k;i<n;i++){s+=a[i]-a[i-k];printf("%lld\n",s);}return 0;}
