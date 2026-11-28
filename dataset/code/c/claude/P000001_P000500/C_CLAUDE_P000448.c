#include<stdio.h>
int main(){long long n;scanf("%lld",&n);long long lo=0,hi=n;while(lo<hi){long long m=(lo+hi+1)/2;if(m*m<=n)lo=m;else hi=m-1;}printf("%lld\n",lo);}
