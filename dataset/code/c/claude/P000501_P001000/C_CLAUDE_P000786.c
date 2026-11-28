#include<stdio.h>
#include<stdlib.h>
int main(){int n;scanf("%d",&n);long long a[n],pre[n+1],suf[n+1];
for(int i=0;i<n;i++)scanf("%lld",&a[i]);
pre[0]=0;for(int i=0;i<n;i++)pre[i+1]=pre[i]+a[i];
suf[n]=0;for(int i=n-1;i>=0;i--)suf[i]=suf[i+1]+a[i];
for(int i=0;i<n;i++)printf("%lld%c",llabs(pre[i]-suf[i+1]),i<n-1?' ':'\n');}
