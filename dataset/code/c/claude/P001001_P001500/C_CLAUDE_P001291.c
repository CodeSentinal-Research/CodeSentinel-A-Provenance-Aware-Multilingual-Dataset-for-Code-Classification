#include <stdio.h>
int main(){int n;scanf("%d",&n);long long a[n],s=0;for(int i=0;i<n;i++){scanf("%lld",&a[i]);s+=a[i];}printf("%lld\n",s);return 0;}
