#include <stdio.h>
long long pw(long long b,long long e,long long m){long long r=1;b%=m;while(e>0){if(e&1)r=r*b%m;b=b*b%m;e>>=1;}return r;}
int main(){long long b,e,m;scanf("%lld %lld %lld",&b,&e,&m);printf("%lld\n",pw(b,e,m));return 0;}
