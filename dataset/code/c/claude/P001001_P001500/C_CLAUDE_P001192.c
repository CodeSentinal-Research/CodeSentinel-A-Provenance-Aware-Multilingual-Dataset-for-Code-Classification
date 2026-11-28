#include <stdio.h>
int main(){int n;scanf("%d",&n);long long a[n];for(int i=0;i<n;i++)scanf("%lld",&a[i]);if(n==1){printf("%lld\n",a[0]);return 0;}long long p2=a[0],p1=a[0]>a[1]?a[0]:a[1];for(int i=2;i<n;i++){long long c=p2+a[i];if(c<p1)c=p1;p2=p1;p1=c;}printf("%lld\n",p1);return 0;}
