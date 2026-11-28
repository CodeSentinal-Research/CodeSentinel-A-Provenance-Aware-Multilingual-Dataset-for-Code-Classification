#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int goal;scanf("%d",&goal);
long long ans=0;int s=0;int cnt[n+1];for(int i=0;i<=n;i++)cnt[i]=0;cnt[0]=1;
for(int i=0;i<n;i++){s+=a[i];if(s-goal>=0)ans+=cnt[s-goal];cnt[s]++;}
printf("%lld\n",ans);}
