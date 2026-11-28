#include<stdio.h>
#define MOD 1000000007LL
int main(){int n;scanf("%d",&n);long long a[n+1],stk[n+2],top=0;for(int i=0;i<n;i++)scanf("%lld",&a[i]);a[n]=-1;long long res=0;for(int i=0;i<=n;i++){while(top>0&&a[stk[top-1]]>=a[i]){long long mid=stk[--top];long long left=top>0?stk[top-1]:-1;res=(res+a[mid]*(mid-left)*(i-mid))%MOD;}stk[top++]=i;}printf("%lld\n",res);}
