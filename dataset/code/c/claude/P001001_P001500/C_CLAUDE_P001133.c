#include <stdio.h>
int main(){int n;scanf("%d",&n);if(n<=2){printf("%d\n",n);return 0;}long long a=1,b=2;for(int i=3;i<=n;i++){long long c=a+b;a=b;b=c;}printf("%lld\n",b);return 0;}
