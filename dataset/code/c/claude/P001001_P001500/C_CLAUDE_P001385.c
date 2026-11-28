#include <stdio.h>
int main(){int n;scanf("%d",&n);long long exp=(long long)n*(n+1)/2,act=0;for(int i=0;i<n-1;i++){long long x;scanf("%lld",&x);act+=x;}printf("%lld\n",exp-act);return 0;}
