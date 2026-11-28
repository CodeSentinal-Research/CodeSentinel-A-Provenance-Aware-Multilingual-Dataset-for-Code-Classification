#include<stdio.h>
int main(){int n;scanf("%d",&n);long long pre[n+1];pre[0]=0;int v;
for(int i=0;i<n;i++){scanf("%d",&v);pre[i+1]=pre[i]+v;}
int q;scanf("%d",&q);while(q--){int l,r;scanf("%d %d",&l,&r);printf("%lld\n",pre[r+1]-pre[l]);}
}
