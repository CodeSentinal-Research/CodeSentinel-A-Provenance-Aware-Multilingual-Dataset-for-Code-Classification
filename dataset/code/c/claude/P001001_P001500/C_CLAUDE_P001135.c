#include <stdio.h>
int main(){int n;scanf("%d",&n);long long mx=-1e18,cur=0;for(int i=0;i<n;i++){long long x;scanf("%lld",&x);cur+=x;if(cur>mx)mx=cur;if(cur<0)cur=0;}printf("%lld\n",mx);return 0;}
