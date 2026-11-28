#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int k;scanf("%d",&k);
int cnt[n+2];for(int i=0;i<=n+1;i++)cnt[i]=0;cnt[0]=1;int odds=0;long long ans=0;
for(int i=0;i<n;i++){odds+=a[i]%2;if(odds-k>=0)ans+=cnt[odds-k];cnt[odds]++;}
printf("%lld\n",ans);}
