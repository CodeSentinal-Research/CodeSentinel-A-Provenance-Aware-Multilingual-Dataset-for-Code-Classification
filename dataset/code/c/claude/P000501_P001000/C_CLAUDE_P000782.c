#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
int q;scanf("%d",&q);while(q--){int l,r,cnt=0;scanf("%d %d",&l,&r);
    for(int i=0;i<n;i++)if(a[i]>=l&&a[i]<=r)cnt++;printf("%d\n",cnt);}
}
