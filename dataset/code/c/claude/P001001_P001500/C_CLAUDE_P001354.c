#include <stdio.h>
long long fib(int n){if(n<=1)return n;long long a=0,b=1;for(int i=2;i<=n;i++){long long c=a+b;a=b;b=c;}return b;}
int main(){int n;scanf("%d",&n);printf("%lld\n",fib(n));return 0;}
