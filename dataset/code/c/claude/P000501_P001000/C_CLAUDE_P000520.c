#include<stdio.h>
#define MOD 1000000007LL
int main(){int n;scanf("%d",&n);long long a[n];for(int i=0;i<n;i++)scanf("%lld",&a[i]);
long long pre[n+1],pp[n+2],left[n],right[n];int stk[n],top=0;
pre[0]=0;for(int i=0;i<n;i++)pre[i+1]=(pre[i]+a[i])%MOD;
pp[0]=0;for(int i=0;i<=n;i++)pp[i+1]=(pp[i]+pre[i+1])%MOD;
top=0;for(int i=0;i<n;i++){while(top>0&&a[stk[top-1]]>=a[i])top--;left[i]=top>0?stk[top-1]:-1;stk[top++]=i;}
top=0;for(int i=n-1;i>=0;i--){while(top>0&&a[stk[top-1]]>a[i])top--;right[i]=top>0?stk[top-1]:n;stk[top++]=i;}
long long ans=0;
for(int i=0;i<n;i++){int l=left[i]+1,r=right[i]-1;long long cl=i-l+1,cr=r-i;
long long tot=((pp[r+2]-pp[i+1]+MOD)%MOD*cl%MOD-(pp[i+1]-pp[l]+MOD)%MOD*cr%MOD+MOD)%MOD;
ans=(ans+a[i]%MOD*tot)%MOD;}
printf("%lld\n",ans);}
