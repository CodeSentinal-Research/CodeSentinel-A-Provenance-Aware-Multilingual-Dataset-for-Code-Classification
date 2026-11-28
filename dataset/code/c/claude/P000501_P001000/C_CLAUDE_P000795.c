#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int k;scanf("%d",&k);
int cnt[k];for(int i=0;i<k;i++)cnt[i]=0;cnt[0]=1;int s=0;long long ans=0;
for(int i=0;i<n;i++){s=((s+a[i])%k+k)%k;ans+=cnt[s];cnt[s]++;}
printf("%lld\n",ans);}
