#include <stdio.h>
int main(){long long n;scanf("%lld",&n);if(n<0)n=-n;int s=0;while(n>0){s+=n%10;n/=10;}printf("%d\n",s);return 0;}
