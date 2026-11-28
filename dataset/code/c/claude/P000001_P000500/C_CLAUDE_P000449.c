#include<stdio.h>
#include<math.h>
int main(){long long n;scanf("%lld",&n);long long r=(long long)sqrt((double)n);while(r*r>n)r--;while((r+1)*(r+1)<=n)r++;printf("%s\n",r*r==n?"Yes":"No");}
