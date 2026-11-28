#include <stdio.h>
long long modpow(long long b, long long e, long long m) { long long r=1; b%=m; while(e>0) { if(e%2) r=(r*b)%m; b=(b*b)%m; e/=2; } return r; }
int main() { long long n; scanf("%lld",&n); long long even=(n+1)/2, odd=n/2; long long res=(modpow(5,even,1000000007)*modpow(4,odd,1000000007))%1000000007; printf("%lld\n",res); return 0; }
