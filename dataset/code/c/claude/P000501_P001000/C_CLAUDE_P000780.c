#include<stdio.h>
int main(){int n;scanf("%d",&n);long long s=0;int v;
for(int i=0;i<n;i++){scanf("%d",&v);s+=v;printf("%lld%c",s,i<n-1?' ':'\n');}}
