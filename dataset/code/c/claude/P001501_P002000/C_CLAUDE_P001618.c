#include <stdio.h>
int main(){int n;scanf("%d",&n);long long a[n],p[n+1];p[0]=0;for(int i=0;i<n;i++){scanf("%lld",&a[i]);p[i+1]=p[i]+a[i];}int q;scanf("%d",&q);while(q--){int l,r;scanf("%d %d",&l,&r);printf("%lld\n",p[r+1]-p[l]);}return 0;}
